#include "PluginEditor.h"

VelvetSaturationAudioProcessorEditor::VelvetSaturationAudioProcessorEditor (VelvetSaturationAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
}

VelvetSaturationAudioProcessorEditor::~VelvetSaturationAudioProcessorEditor() {}

void VelvetSaturationAudioProcessorEditor::paint (juce::Graphics& g) 
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Velvet Saturation", getLocalBounds(), juce::Justification::centred, 1);
}

void VelvetSaturationAudioProcessorEditor::resized() 
{
    // Resize components if needed
}