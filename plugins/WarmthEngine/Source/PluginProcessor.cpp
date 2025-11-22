#include "PluginProcessor.h"
#include "PluginEditor.h"

WarmthEngineAudioProcessor::WarmthEngineAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true))
#endif
{
}

WarmthEngineAudioProcessor::~WarmthEngineAudioProcessor() = default;

void WarmthEngineAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Prepare for playback; can be set up here
}

void WarmthEngineAudioProcessor::releaseResources()
{
    // Release resources as needed
}

void WarmthEngineAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear any output channels that don't contain input data
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        // Apply saturation processing
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float drySample = channelData[sample];
            float wetSample = juce::tanh(drySample * saturationLevel); // Simple tanh saturation
            channelData[sample] = (1.0f - dryWet) * drySample + dryWet * wetSample;
        }
    }
}

juce::AudioProcessorEditor* WarmthEngineAudioProcessor::createEditor()
{
    return new WarmthEngineAudioProcessorEditor (*this);
}

bool WarmthEngineAudioProcessor::hasEditor() const
{
    return true;
}

const juce::String WarmthEngineAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool WarmthEngineAudioProcessor::acceptsMidi() const { return false; }
bool WarmthEngineAudioProcessor::producesMidi() const { return false; }
bool WarmthEngineAudioProcessor::isMidiEffect() const { return false; }

void WarmthEngineAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // Store the parameter values
    auto data = juce::MemoryOutputStream (destData, true);
    data.writeFloat(saturationLevel);
    data.writeFloat(dryWet);
}

void WarmthEngineAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    auto dataStream = juce::MemoryInputStream (data, sizeInBytes, false);
    saturationLevel = dataStream.readFloat();
    dryWet = dataStream.readFloat();
}