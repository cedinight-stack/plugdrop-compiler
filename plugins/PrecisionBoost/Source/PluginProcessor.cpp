#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PrecisionBoostAudioProcessor::PrecisionBoostAudioProcessor()
     : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true))
{
    addParameter(gainParameter = new juce::AudioParameterFloat("gain", "Gain", -12.0f, 12.0f, 0.0f));
}

PrecisionBoostAudioProcessor::~PrecisionBoostAudioProcessor()
{
}

void PrecisionBoostAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void PrecisionBoostAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PrecisionBoostAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;
    return true;
}
#endif

void PrecisionBoostAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear output buffers
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    float gainValue = gainParameter->get();

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            channelData[sample] = juce::jlimit(-1.0f, 1.0f, channelData[sample] * juce::Decibels::decibelsToGain(gainValue));
        }
    }
}

juce::AudioProcessorEditor* PrecisionBoostAudioProcessor::createEditor()
{
    return new PrecisionBoostAudioProcessorEditor (*this);
}

void PrecisionBoostAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    juce::MemoryOutputStream stream (destData, true);
    stream.writeFloat (gainParameter->get());
}

void PrecisionBoostAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    if (sizeInBytes == sizeof(float))
    {
        float gainValue = *static_cast<const float*>(data);
        gainParameter->setValueNotifyingHost(gainValue);
    }
}