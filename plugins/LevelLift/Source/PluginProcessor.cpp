#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LevelLiftAudioProcessor::LevelLiftAudioProcessor()
    : AudioProcessor (BusesProperties().withInput ("Input", juce::AudioChannelSet::stereo(), true).withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
      parameters (*this, nullptr, "Parameters", 
                  {
                      std::make_unique<juce::AudioParameterFloat>("gain", "Gain", -60.0f, 12.0f, 0.0f)
                  })
{
    gainParameter = parameters.getRawParameterValue("gain");
}

LevelLiftAudioProcessor::~LevelLiftAudioProcessor() {}

void LevelLiftAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) {}

void LevelLiftAudioProcessor::releaseResources() {}

void LevelLiftAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear output channels
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // Process each channel
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        float gainValue = juce::Decibels::decibelsToGain(*gainParameter);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            channelData[sample] *= gainValue;
        }
    }
}

bool LevelLiftAudioProcessor::hasEditor() const { return true; }

juce::AudioProcessorEditor* LevelLiftAudioProcessor::createEditor()
{
    return new LevelLiftAudioProcessorEditor (*this);
}

void LevelLiftAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = parameters.copyState();
    std::unique_ptr<juce::MemoryOutputStream> stream = std::make_unique<juce::MemoryOutputStream>(destData, false);
    state.writeToStream(*stream);
}

void LevelLiftAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    auto treeState = juce::ValueTree::readFromData(data, sizeInBytes);
    if (treeState.isValid())
    {
        parameters.replaceState(treeState);
    }
}