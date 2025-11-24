#pragma once

#include "PluginProcessor.h"

class SmoothSaturateAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SmoothSaturateAudioProcessorEditor (SmoothSaturateAudioProcessor&);
    ~SmoothSaturateAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SmoothSaturateAudioProcessor& audioProcessor;

    juce::ScopedPointer<juce::Slider> smoothGainSlider;
    juce::ScopedPointer<juce::Label> smoothGainLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SmoothSaturateAudioProcessorEditor)
};