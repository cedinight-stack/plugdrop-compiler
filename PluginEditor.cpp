#include "PluginEditor.h"
#include "PluginProcessor.h"

SimplePluginAudioProcessorEditor::SimplePluginAudioProcessorEditor (SimplePluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (400, 300);
}

SimplePluginAudioProcessorEditor::~SimplePluginAudioProcessorEditor() {}

void SimplePluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void SimplePluginAudioProcessorEditor::resized() {}
