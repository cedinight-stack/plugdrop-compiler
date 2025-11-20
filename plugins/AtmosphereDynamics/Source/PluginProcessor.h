#pragma once

#include <JuceHeader.h>

class AtmosphereDynamicsAudioProcessor  : public juce::AudioProcessor
{
public:
    AtmosphereDynamicsAudioProcessor();
    ~AtmosphereDynamicsAudioProcessor() override;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
    #endif
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    juce::AudioProcessorValueTreeState parameters;
    juce::AudioParameterFloat* threshold;
    juce::AudioParameterFloat* ratio;
    juce::AudioParameterFloat* attack;
    juce::AudioParameterFloat* release;
    juce::AudioParameterFloat* makeUpGain;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AtmosphereDynamicsAudioProcessor)
};