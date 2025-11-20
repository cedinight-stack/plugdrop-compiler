#pragma once

#include "PluginProcessor.h"

//==============================================================================
class LevelLiftAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    LevelLiftAudioProcessorEditor (LevelLiftAudioProcessor& p);
    ~LevelLiftAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    LevelLiftAudioProcessor& audioProcessor;

    // Sliders and labels
    juce::Slider gainSlider;
    juce::Label gainLabel;

    // Attach parameters
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LevelLiftAudioProcessorEditor)
};