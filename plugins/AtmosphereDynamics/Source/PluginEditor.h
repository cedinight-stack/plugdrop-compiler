#pragma once

#include "PluginProcessor.h"

class AtmosphereDynamicsAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    AtmosphereDynamicsAudioProcessorEditor (AtmosphereDynamicsAudioProcessor& p);
    ~AtmosphereDynamicsAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    AtmosphereDynamicsAudioProcessor& audioProcessor;

    juce::Slider thresholdSlider;
    juce::Slider ratioSlider;
    juce::Slider attackSlider;
    juce::Slider releaseSlider;
    juce::Slider makeUpGainSlider;
    
    juce::Label thresholdLabel;
    juce::Label ratioLabel;
    juce::Label attackLabel;
    juce::Label releaseLabel;
    juce::Label makeUpGainLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AtmosphereDynamicsAudioProcessorEditor)
};