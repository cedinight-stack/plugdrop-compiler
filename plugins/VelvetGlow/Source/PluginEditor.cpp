#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VelvetGlowAudioProcessorEditor::VelvetGlowAudioProcessorEditor (VelvetGlowAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    saturationSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    saturationSlider.setRange(0.0, 1.0);
    saturationSlider.setValue(audioProcessor.saturationAmount->getValue());
    saturationSlider.addListener(this);
    addAndMakeVisible(saturationSlider);

    outputGainSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    outputGainSlider.setRange(-12.0, 12.0);
    outputGainSlider.setValue(audioProcessor.outputGain->getValue());
    outputGainSlider.addListener(this);
    addAndMakeVisible(outputGainSlider);

    saturationLabel.setText("Saturation", juce::dontSendNotification);
    addAndMakeVisible(saturationLabel);

    outputGainLabel.setText("Output Gain", juce::dontSendNotification);
    addAndMakeVisible(outputGainLabel);

    setSize (400, 200);
}

VelvetGlowAudioProcessorEditor::~VelvetGlowAudioProcessorEditor() {}

void VelvetGlowAudioProcessorEditor::paint (juce::Graphics& g) {
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.drawFittedText ("VelvetGlow", getLocalBounds(), juce::Justification::centred, 1);
}

void VelvetGlowAudioProcessorEditor::resized() {
    saturationLabel.setBounds (20, 40, 100, 20);
    saturationSlider.setBounds (130, 40, 240, 20);
    
    outputGainLabel.setBounds (20, 80, 100, 20);
    outputGainSlider.setBounds (130, 80, 240, 20);
}