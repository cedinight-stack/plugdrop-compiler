#pragma once

#include "PluginProcessor.h"

class GateKeeperAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GateKeeperAudioProcessorEditor (GateKeeperAudioProcessor&);
    ~GateKeeperAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    GateKeeperAudioProcessor& processor;

    juce::Slider thresholdSlider;
    juce::Slider releaseTimeSlider;

    juce::Label thresholdLabel;
    juce::Label releaseTimeLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GateKeeperAudioProcessorEditor)
};