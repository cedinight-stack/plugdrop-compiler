#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SilenceSculptorAudioProcessor::SilenceSculptorAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
 : AudioProcessor (BusesProperties().withInput ("Input", juce::AudioChannelSet::stereo(), true)
                        .withOutput ("Output", juce::AudioChannelSet::stereo(), true))
#endif
{
    // Initialize parameters
    addParameter(thresholdParam = new juce::AudioParameterFloat("threshold", "Threshold", -80.0f, 0.0f, -40.0f));
    addParameter(attackParam = new juce::AudioParameterFloat("attack", "Attack", 0.0f, 200.0f, 10.0f));
    addParameter(holdParam = new juce::AudioParameterFloat("hold", "Hold", 0.0f, 5000.0f, 500.0f));
    addParameter(releaseParam = new juce::AudioParameterFloat("release", "Release", 0.0f, 2000.0f, 100.0f));
}

SilenceSculptorAudioProcessor::~SilenceSculptorAudioProcessor() {}

void SilenceSculptorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) {}

void SilenceSculptorAudioProcessor::releaseResources() {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SilenceSculptorAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}
#endif

void SilenceSculptorAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear output channels
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i);

    auto threshold = thresholdParam->get();
    auto attack = attackParam->get();
    auto hold = holdParam->get();
    auto release = releaseParam->get();

    // Process audio
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        // Apply noise gate logic here
        // Simple example of threshold, attack, hold, release would go here
    }
}

juce::AudioProcessorEditor* SilenceSculptorAudioProcessor::createEditor()
{
    return new SilenceSculptorAudioProcessorEditor (*this);
}

void SilenceSculptorAudioProcessor::getStateInformation (juce::MemoryBlock& destData) {}

void SilenceSculptorAudioProcessor::setStateInformation (const void* data, int sizeInBytes) {}