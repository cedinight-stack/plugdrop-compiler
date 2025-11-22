#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WarmthWaveAudioProcessorEditor::WarmthWaveAudioProcessorEditor (WarmthWaveAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Slider setup
    saturationSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    saturationSlider.setRange(0.0f, 1.0f);
    saturationSlider.setValue(0.5f);
    saturationSlider.addListener(this);
    addAndMakeVisible(saturationSlider);
    
    saturationLabel.setText("Saturation", juce::dontSendNotification);
    addAndMakeVisible(saturationLabel);
    
    setSize (400, 200);
}

WarmthWaveAudioProcessorEditor::~WarmthWaveAudioProcessorEditor() {}

void WarmthWaveAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour::fromRGB(42, 42, 42));
    g.setColour (juce::Colours::white);
    g.drawFittedText ("WarmthWave", getLocalBounds(), juce::Justification::centred, 1);
}

void WarmthWaveAudioProcessorEditor::resized()
{
    saturationSlider.setBounds (40, 80, getWidth() - 80, 20);
    saturationLabel.setBounds (40, 50, getWidth() - 80, 20);
}