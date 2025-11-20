#include "PluginEditor.h"

//==============================================================================
TapeWarmthAudioProcessorEditor::TapeWarmthAudioProcessorEditor (TapeWarmthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(juce::Slider::LinearVertical);
    gainSlider.setRange(-12.0f, 12.0f, 0.1f);
    gainSlider.setValue(0.0f);
    gainSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    addAndMakeVisible(gainSlider);

    saturationSlider.setSliderStyle(juce::Slider::LinearVertical);
    saturationSlider.setRange(0.0f, 1.0f, 0.01f);
    saturationSlider.setValue(0.5f);
    saturationSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    addAndMakeVisible(saturationSlider);

    gainLabel.setText("Gain", juce::dontSendNotification);
    gainLabel.attachToComponent(&gainSlider, true);
    addAndMakeVisible(gainLabel);

    saturationLabel.setText("Saturation", juce::dontSendNotification);
    saturationLabel.attachToComponent(&saturationSlider, true);
    addAndMakeVisible(saturationLabel);

    setSize (300, 200);
}

TapeWarmthAudioProcessorEditor::~TapeWarmthAudioProcessorEditor() {}

void TapeWarmthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void TapeWarmthAudioProcessorEditor::resized()
{
    gainSlider.setBounds(30, 40, 50, 150);
    saturationSlider.setBounds(120, 40, 50, 150);
}