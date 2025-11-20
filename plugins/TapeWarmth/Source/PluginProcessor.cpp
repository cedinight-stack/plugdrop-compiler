#include "PluginProcessor.h"

//==============================================================================
TapeWarmthAudioProcessor::TapeWarmthAudioProcessor()
    : parameters(*this, nullptr, "PARAMETERS", 
                 {
                     std::make_unique<juce::AudioParameterFloat>("gain", "Gain", -12.0f, 12.0f, 0.0f),
                     std::make_unique<juce::AudioParameterFloat>("saturation", "Saturation", 0.0f, 1.0f, 0.5f)
                 })
{
    gainParameter = parameters.getRawParameterValue("gain");
    saturationParameter = parameters.getRawParameterValue("saturation");
}

TapeWarmthAudioProcessor::~TapeWarmthAudioProcessor() {}

void TapeWarmthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) {}

void TapeWarmthAudioProcessor::releaseResources() {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TapeWarmthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet().size() > 0;
}
#endif

void TapeWarmthAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalSamples = buffer.getNumSamples();

    float gain = gainParameter->load();
    float saturation = saturationParameter->load();
    
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);
        for (int sample = 0; sample < totalSamples; ++sample)
        {
            // Apply simple saturation effect - this is a placeholder for a more complex saturation algorithm
            float sampleValue = channelData[sample];

            // Gain adjustment
            sampleValue *= juce::Decibels::decibelsToGain(gain);
            
            // Saturation logic
            if (saturation > 0.0f)
            {
                float overdrive = sampleValue - (saturation * sampleValue * sampleValue);
                sampleValue = std::tanh(overdrive);
            }

            channelData[sample] = sampleValue;
        }
    }
}