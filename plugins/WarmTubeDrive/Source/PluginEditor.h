#pragma once

#include "PluginProcessor.h"

//==============================================================================
class WarmTubeDriveAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    WarmTubeDriveAudioProcessorEditor (WarmTubeDriveAudioProcessor&);
    ~WarmTubeDriveAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    WarmTubeDriveAudioProcessor& audioProcessor;

    // UI Components
    juce::Slider gainSlider;
    juce::Slider driveSlider;
    juce::Label gainLabel;
    juce::Label driveLabel;

    juce::AudioProcessorValueTreeState::SliderAttachment gainAttachment;
    juce::AudioProcessorValueTreeState::SliderAttachment driveAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WarmTubeDriveAudioProcessorEditor)
};