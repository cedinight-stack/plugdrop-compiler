#pragma once

#include <JuceHeader.h>

class GateKeeperAudioProcessor  : public juce::AudioProcessor
{
public:
    GateKeeperAudioProcessor();
    ~GateKeeperAudioProcessor() override;

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    // Parameters
    float getThreshold() const { return threshold; }
    float getReleaseTime() const { return releaseTime; }

    void setThreshold(float newThreshold) { threshold = newThreshold; }
    void setReleaseTime(float newReleaseTime) { releaseTime = newReleaseTime; }

private:
    // Parameters
    float threshold;
    float releaseTime;
    juce::dsp::Gain<float> gain;
    float releaseCoefficient;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GateKeeperAudioProcessor)
};