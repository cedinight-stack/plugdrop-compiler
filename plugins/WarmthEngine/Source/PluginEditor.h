#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class WarmthEngineAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    WarmthEngineAudioProcessorEditor (WarmthEngineAudioProcessor&);
    ~WarmthEngineAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    WarmthEngineAudioProcessor& audioProcessor;

    juce::Slider saturationSlider;
    juce::Slider dryWetSlider;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WarmthEngineAudioProcessorEditor)
};