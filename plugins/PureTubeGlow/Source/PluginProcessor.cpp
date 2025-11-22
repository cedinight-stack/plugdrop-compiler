#include "PluginProcessor.h"

//==============================================================================
PureTubeGlowAudioProcessor::PureTubeGlowAudioProcessor()
    : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
    parameters (*this, nullptr, "Parameters", {
        std::make_unique<juce::AudioParameterFloat>("gain", "Gain", 1.0f, 10.0f, 1.0f)
    })
{
}

PureTubeGlowAudioProcessor::~PureTubeGlowAudioProcessor() {}

void PureTubeGlowAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) {
    gain = *parameters.getRawParameterValue("gain");
}

void PureTubeGlowAudioProcessor::releaseResources() {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PureTubeGlowAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const {
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;
    return true;
}
#endif

void PureTubeGlowAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) {
    gain = *parameters.getRawParameterValue("gain");

    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        auto* channelData = buffer.getWritePointer (channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
            // Simple tube saturation emulation
            auto inputSample = channelData[sample];
            auto distortedSample = inputSample * gain;

            // Simple soft clipping
            if (distortedSample > 1.0f) distortedSample = 1.0f; 
            else if (distortedSample < -1.0f) distortedSample = -1.0f; 

            channelData[sample] = distortedSample;
        }
    }
}