#include "PluginEditor.h"

//==============================================================================
SilenceSculptorAudioProcessorEditor::SilenceSculptorAudioProcessorEditor (SilenceSculptorAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
}

SilenceSculptorAudioProcessorEditor::~SilenceSculptorAudioProcessorEditor() {}

void SilenceSculptorAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour (0xff323e44));
}

void SilenceSculptorAudioProcessorEditor::resized()
{
    // Layout your UI components here
}