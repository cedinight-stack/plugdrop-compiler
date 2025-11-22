#pragma once

#include "PluginProcessor.h"

//==============================================================================
class GainGuardAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GainGuardAudioProcessorEditor (GainGuardAudioProcessor&);
    ~GainGuardAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    GainGuardAudioProcessor& processor;

    juce::Slider inputGainSlider;
    juce::Slider outputGainSlider;
    juce::ToggleButton muteButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainGuardAudioProcessorEditor)
};