#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ClearCutGateAudioProcessor::ClearCutGateAudioProcessor()
{
}

ClearCutGateAudioProcessor::~ClearCutGateAudioProcessor()
{
}

//==============================================================================
void ClearCutGateAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
}

void ClearCutGateAudioProcessor::releaseResources()
{
}

bool ClearCutGateAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    return true;
}

void ClearCutGateAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getPointer(channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            // Basic gating logic
            float input = channelData[sample];
            float thresholdValue = juce::Decibels::decibelsToGain(threshold);
            if (isActive)
            {
                if (input > thresholdValue)
                    channelData[sample] = input; // Signal goes through
                else
                    channelData[sample] = 0.0f; // Gated out
            }
        }
    }
}

juce::AudioProcessorEditor* ClearCutGateAudioProcessor::createEditor()
{
    return new ClearCutGateAudioProcessorEditor(*this);
}

void ClearCutGateAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
}

void ClearCutGateAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
}