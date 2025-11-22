#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class VelvetSaturationAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    VelvetSaturationAudioProcessorEditor (VelvetSaturationAudioProcessor&);
    ~VelvetSaturationAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    VelvetSaturationAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VelvetSaturationAudioProcessorEditor)
};