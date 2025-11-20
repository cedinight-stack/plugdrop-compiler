#pragma once

#include <JuceHeader.h>

//==============================================================================
class LevelLiftAudioProcessor : public juce::AudioProcessor
{
public:
    //==============================================================================
    LevelLiftAudioProcessor();
    ~LevelLiftAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //==============================================================================
    juce::AudioProcessorValueTreeState parameters;

    // Gain parameter
    std::unique_ptr<juce::AudioParameterFloat> gainParameter;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LevelLiftAudioProcessor)
};