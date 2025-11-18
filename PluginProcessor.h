#pragma once
#include <JuceHeader.h>

class SimplePluginAudioProcessor : public juce::AudioProcessor
{
public:
    SimplePluginAudioProcessor();
    ~SimplePluginAudioProcessor() override;

    void prepareToPlay (double, int) override;
    void releaseResources() override;
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    const juce::String getName() const override { return "SimplePlugin"; }
    double getTailLengthSeconds() const override { return 0.0; }

    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimplePluginAudioProcessor)
};
