#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TubeGlowAudioProcessorEditor::TubeGlowAudioProcessorEditor (TubeGlowAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Gain slider setup
    gainSlider.setSliderStyle(juce::Slider::LinearVertical);
    gainSlider.setRange(0.0f, 10.0f);
    gainSlider.setValue(processor.gainParameter);
    gainSlider.onValueChange = [this] { processor.gainParameter = gainSlider.getValue(); };
    addAndMakeVisible(gainSlider);

    // Mix slider setup
    mixSlider.setSliderStyle(juce::Slider::LinearVertical);
    mixSlider.setRange(0.0f, 1.0f);
    mixSlider.setValue(processor.mixParameter);
    mixSlider.onValueChange = [this] { processor.mixParameter = mixSlider.getValue(); };
    addAndMakeVisible(mixSlider);

    // Labels for sliders
    gainLabel.setText("Gain", juce::dontSendNotification);
    mixLabel.setText("Mix", juce::dontSendNotification);
    addAndMakeVisible(gainLabel);
    addAndMakeVisible(mixLabel);

    setSize (200, 300);
}

TubeGlowAudioProcessorEditor::~TubeGlowAudioProcessorEditor()
{
}

void TubeGlowAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawText ("TubeGlow Saturation", getLocalBounds(), juce::Justification::centred, true);
}

void TubeGlowAudioProcessorEditor::resized()
{
    gainSlider.setBounds (20, 40, 60, 200);
    gainLabel.setBounds (20, 10, 60, 20);
    
    mixSlider.setBounds (100, 40, 60, 200);
    mixLabel.setBounds (100, 10, 60, 20);
}