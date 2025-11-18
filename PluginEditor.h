#pragma once
#include <JuceHeader.h>

class SimplePluginAudioProcessor;

class SimplePluginAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    SimplePluginAudioProcessorEditor (SimplePluginAudioProcessor&);
    ~SimplePluginAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SimplePluginAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimplePluginAudioProcessorEditor)
};
