#pragma once

#include <JuceHeader.h>

//==============================================================================
class TapeWarmthAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    TapeWarmthAudioProcessor();
    ~TapeWarmthAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
    #endif
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorValueTreeState parameters;
    float getGain() const;
    float getSaturation() const;

private:
    //==============================================================================
    juce::AudioParameterFloat* gainParameter;
    juce::AudioParameterFloat* saturationParameter;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TapeWarmthAudioProcessor)
};