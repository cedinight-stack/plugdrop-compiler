#pragma once

#include <JuceHeader.h>

//==============================================================================
class SilenceSculptorAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    SilenceSculptorAudioProcessor();
    ~SilenceSculptorAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
    #endif
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    // Your parameters here
    juce::AudioParameterFloat* thresholdParam;
    juce::AudioParameterFloat* attackParam;
    juce::AudioParameterFloat* holdParam;
    juce::AudioParameterFloat* releaseParam;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SilenceSculptorAudioProcessor)
};