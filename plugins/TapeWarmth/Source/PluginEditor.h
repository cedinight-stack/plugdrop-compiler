#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
class TapeWarmthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    TapeWarmthAudioProcessorEditor (TapeWarmthAudioProcessor&);
    ~TapeWarmthAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    TapeWarmthAudioProcessor& audioProcessor;

    juce::Slider gainSlider;
    juce::Slider saturationSlider;
    juce::Label gainLabel;
    juce::Label saturationLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TapeWarmthAudioProcessorEditor)
};