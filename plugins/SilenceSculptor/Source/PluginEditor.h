#pragma once

#include "PluginProcessor.h"

//==============================================================================
class SilenceSculptorAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SilenceSculptorAudioProcessorEditor (SilenceSculptorAudioProcessor&);
    ~SilenceSculptorAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SilenceSculptorAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SilenceSculptorAudioProcessorEditor)
};