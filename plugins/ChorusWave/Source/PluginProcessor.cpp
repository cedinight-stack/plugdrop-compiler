#include "PluginProcessor.h"

//==============================================================================
ChorusWaveAudioProcessor::ChorusWaveAudioProcessor()
    : parameters(*this, nullptr)
{
    parameters.createAndAddParameter("rate", "Rate", "Chorus Rate", 
        juce::NormalisableRange<float>(0.1f, 10.0f), 1.0f, nullptr, nullptr);
    parameters.createAndAddParameter("depth", "Depth", "Chorus Depth", 
        juce::NormalisableRange<float>(0.f, 1.f), 0.5f, nullptr, nullptr);
    parameters.state = juce::ValueTree("ChorusWave");
    
    chorus = std::make_unique<juce::dsp::Chorus<float>>();
}

ChorusWaveAudioProcessor::~ChorusWaveAudioProcessor() {}

//==============================================================================
void ChorusWaveAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    currentSampleRate = sampleRate;
    chorus->setRate(*parameters.getRawParameterValue("rate"));
    chorus->setDepth(*parameters.getRawParameterValue("depth"));
    chorus->setSampleRate(sampleRate);
}

void ChorusWaveAudioProcessor::releaseResources() {}

void ChorusWaveAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);
        chorus->processMono(channelData, buffer.getNumSamples());
    }
}