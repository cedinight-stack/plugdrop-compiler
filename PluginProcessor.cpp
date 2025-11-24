#include "PluginProcessor.h"
#include "PluginEditor.h"

SmoothSaturateAudioProcessor::SmoothSaturateAudioProcessor()
    : parameters(*this, nullptr, juce::Identifier("Parameters"),
                 {
                     std::make_unique<juce::AudioParameterFloat>("smoothGain", "Smooth Gain", 0.0f, 10.0f, 1.0f)
                 })
{
}

SmoothSaturateAudioProcessor::~SmoothSaturateAudioProcessor()
{
}

void SmoothSaturateAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    smoothGain = *parameters.getRawParameterValue("smoothGain");
}

void SmoothSaturateAudioProcessor::releaseResources()
{
}

void SmoothSaturateAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    
    // Get Smooth Gain value
    smoothGain = *parameters.getRawParameterValue("smoothGain");

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        // Simple saturation algorithm
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float cleanSample = channelData[sample];
            float saturatedSample = std::tanh(cleanSample * smoothGain);
            channelData[sample] = saturatedSample;
        }
    }
}

juce::AudioProcessorEditor* SmoothSaturateAudioProcessor::createEditor()
{
    return new SmoothSaturateAudioProcessorEditor (*this);
}

bool SmoothSaturateAudioProcessor::hasEditor() const
{
    return true;
}

void SmoothSaturateAudioProcessor::reset()
{
    // Add reset logic if needed.
}

JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SmoothSaturateAudioProcessor)