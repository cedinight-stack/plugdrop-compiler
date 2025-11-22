#pragma once

#include <JuceHeader.h>

class WarmthEngineAudioProcessor : public juce::AudioProcessor
{
public:
    WarmthEngineAudioProcessor();
    ~WarmthEngineAudioProcessor() override;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const juce::String getName() const override;
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    float saturationLevel = 0.5f; // Main parameter for saturation
    float dryWet = 0.5f; // Mix between dry and wet
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WarmthEngineAudioProcessor)
};