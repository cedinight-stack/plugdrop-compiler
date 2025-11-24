#include "PluginEditor.h"

SmoothSaturateAudioProcessorEditor::SmoothSaturateAudioProcessorEditor (SmoothSaturateAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    smoothGainSlider = std::make_unique<juce::Slider>();
    smoothGainLabel = std::make_unique<juce::Label>();
    
    smoothGainSlider->setSliderStyle(juce::Slider::LinearHorizontal);
    smoothGainSlider->setRange(0.0, 10.0);
    smoothGainSlider->setValue(1.0);
    smoothGainSlider->setTextValueSuffix(" dB");
    smoothGainSlider->addListener(this);
    
    smoothGainLabel->setText("Smooth Gain", juce::dontSendNotification);
    smoothGainLabel->attachToComponent(smoothGainSlider.get(), true);

    addAndMakeVisible(smoothGainSlider.get());
    addAndMakeVisible(smoothGainLabel.get());
    
    setSize(400, 300);
}

SmoothSaturateAudioProcessorEditor::~SmoothSaturateAudioProcessorEditor()
{
}

void SmoothSaturateAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.drawText ("Smooth Saturate", getLocalBounds(), juce::Justification::centred, true);
}

void SmoothSaturateAudioProcessorEditor::resized()
{
    smoothGainSlider->setBounds(40, 120, getWidth() - 80, 30);
}