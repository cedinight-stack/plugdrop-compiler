#include "PluginEditor.h"

//==============================================================================
ClearCutGateAudioProcessorEditor::ClearCutGateAudioProcessorEditor(ClearCutGateAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setSize(400, 300);
}

ClearCutGateAudioProcessorEditor::~ClearCutGateAudioProcessorEditor()
{
}

//==============================================================================
void ClearCutGateAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawFittedText("ClearCut Gate", getLocalBounds(), juce::Justification::centred, 1);
}

void ClearCutGateAudioProcessorEditor::resized()
{
}