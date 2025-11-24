#pragma once

#include <JuceHeader.h>

class SmoothSaturateAudioProcessor  : public juce::AudioProcessor
{
public:
    SmoothSaturateAudioProcessor();
    ~SmoothSaturateAudioProcessor() override;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    juce::AudioProcessorValueTreeState parameters;

    void reset();

private:
    float smoothGain;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SmoothSaturateAudioProcessor)
};