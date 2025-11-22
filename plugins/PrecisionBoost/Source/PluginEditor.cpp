#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PrecisionBoostAudioProcessorEditor::PrecisionBoostAudioProcessorEditor (PrecisionBoostAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    gainSlider.setRange(-12.0f, 12.0f);
    gainSlider.setValue(0.0f);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
    
    gainLabel.setText("Gain (dB)", juce::dontSendNotification);
    gainLabel.attachToComponent(&gainSlider, false);
    addAndMakeVisible(gainLabel);

    setSize (300, 150);
}

PrecisionBoostAudioProcessorEditor::~PrecisionBoostAudioProcessorEditor()
{
}

void PrecisionBoostAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour (40, 40, 40));
    g.setColour (juce::Colours::white);
    g.drawFittedText ("PrecisionBoost", 0, 0, getWidth(), 20, juce::Justification::centred, 1);
}

void PrecisionBoostAudioProcessorEditor::resized()
{
    gainSlider.setBounds (40, 50, getWidth() - 80, 20);
}