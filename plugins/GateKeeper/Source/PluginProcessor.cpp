#include "PluginProcessor.h"
#include "PluginEditor.h"

GateKeeperAudioProcessor::GateKeeperAudioProcessor() 
    : threshold(-60.0f), releaseTime(200.0f), releaseCoefficient(0.0f)
{
}

GateKeeperAudioProcessor::~GateKeeperAudioProcessor() {}

void GateKeeperAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    releaseCoefficient = juce::MathConstants<float>::twoPi / (sampleRate * (releaseTime / 1000.0f));
    gain.setGainDecibels(0.0f); // start with 0 dB gain
}

void GateKeeperAudioProcessor::releaseResources() {}

void GateKeeperAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear any output channels that are not being used
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        for (int i = 0; i < buffer.getNumSamples(); ++i)
        {
            float signal = channelData[i];
            float gainValue = 0.0f;

            if (signal > juce::Decibels::decibelsToGain(threshold))
            {
                gainValue = 1.0f; // Full gain
            }
            else
            {
                gainValue = gainValue * releaseCoefficient + (1.0f - releaseCoefficient); // Smooth release
            }

            channelData[i] *= gainValue;
        }
    }
}

juce::AudioProcessorEditor* GateKeeperAudioProcessor::createEditor()
{
    return new GateKeeperAudioProcessorEditor (*this);
}

bool GateKeeperAudioProcessor::hasEditor() const
{
    return true; // This plugin has an editor
}

void GateKeeperAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto* data = destData.resetAndAllocate <float> (2);
    data[0] = threshold;
    data[1] = releaseTime;
}

void GateKeeperAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    auto* params = static_cast<const float*>(data);
    threshold = params[0];
    releaseTime = params[1];
}