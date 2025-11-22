#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainGuardAudioProcessor::GainGuardAudioProcessor()
{
}

GainGuardAudioProcessor::~GainGuardAudioProcessor()
{
}

void GainGuardAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void GainGuardAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool GainGuardAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return (layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo());
}
#endif

void GainGuardAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    for (int channel = 0; channel < getTotalNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getWritePointer(channel);

        // Apply mute
        if (!isMuted)
        {
            // Apply input gain
            for (int i = 0; i < buffer.getNumSamples(); ++i)
                channelData[i] *= inputGain;

            // Apply output gain
            for (int i = 0; i < buffer.getNumSamples(); ++i)
                channelData[i] *= outputGain;
        }
        else
        {
            // Zero out the channel if muted
            buffer.clear(channel, 0, buffer.getNumSamples());
        }
    }
}

juce::AudioProcessorEditor* GainGuardAudioProcessor::createEditor()
{
    return new GainGuardAudioProcessorEditor (*this);
}

bool GainGuardAudioProcessor::hasEditor() const
{
    return true; 
}

void GainGuardAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // Save the necessary state information
    juce::MemoryOutputStream stream (destData, true);
    stream.writeFloat(inputGain);
    stream.writeFloat(outputGain);
    stream.writeBool(isMuted);
}

void GainGuardAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // Restore the state information
    juce::MemoryInputStream stream(data, sizeInBytes, false);
    inputGain = stream.readFloat();
    outputGain = stream.readFloat();
    isMuted = stream.readBool();
}