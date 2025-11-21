#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainCraftAudioProcessor::GainCraftAudioProcessor()
    : AudioProcessor(BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
      gainValue(1.0f) // Default gain value (1.0 = 0 dB)
{
}

GainCraftAudioProcessor::~GainCraftAudioProcessor()
{
}

void GainCraftAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Prepare for playback
}

void GainCraftAudioProcessor::releaseResources()
{
    // Release resources
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool GainCraftAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}
#endif

void GainCraftAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear output buffer
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // Apply gain to each sample
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            channelData[sample] *= gainValue; // Apply gain
        }
    }
}

juce::AudioProcessorEditor* GainCraftAudioProcessor::createEditor()
{
    return new GainCraftAudioProcessorEditor (*this);
}

bool GainCraftAudioProcessor::hasEditor() const
{
    return true;
}

void GainCraftAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // Store the gain value state
    auto state = juce::MemoryOutputStream(destData, false);
    state.writeFloat(gainValue);
}

void GainCraftAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // Restore the gain value state
    if (sizeInBytes >= sizeof(float))
    {
        gainValue = *static_cast<const float*>(data);
    }
}