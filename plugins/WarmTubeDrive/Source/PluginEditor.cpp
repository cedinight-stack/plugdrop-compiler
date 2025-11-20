#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WarmTubeDriveAudioProcessorEditor::WarmTubeDriveAudioProcessorEditor (WarmTubeDriveAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
      gainAttachment(audioProcessor.parameters, "gain", gainSlider),
      driveAttachment(audioProcessor.parameters, "drive", driveSlider)
{
    gainSlider.setRange(0.0, 10.0);
    gainSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    gainSlider.setValue(1.0f);
    addAndMakeVisible(gainSlider);

    driveSlider.setRange(0.0, 1.0);
    driveSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    driveSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 100, 20);
    driveSlider.setValue(0.5f);
    addAndMakeVisible(driveSlider);
    
    gainLabel.setText("Gain", juce::dontSendNotification);
    addAndMakeVisible(gainLabel);
    
    driveLabel.setText("Drive", juce::dontSendNotification);
    addAndMakeVisible(driveLabel);

    setSize (400, 300);
}

WarmTubeDriveAudioProcessorEditor::~WarmTubeDriveAudioProcessorEditor()
{
}

void WarmTubeDriveAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.drawText ("Warm Tube Drive", getLocalBounds(), juce::Justification::centred, true);
}

void WarmTubeDriveAudioProcessorEditor::resized()
{
    auto area = getLocalBounds().reduced(20);
    auto sliderHeight = 80;
    
    gainSlider.setBounds(area.removeFromTop(sliderHeight));
    gainLabel.setBounds(gainSlider.getX(), gainSlider.getY() + sliderHeight, gainSlider.getWidth(), 20);
    
    driveSlider.setBounds(area.removeFromTop(sliderHeight));
    driveLabel.setBounds(driveSlider.getX(), driveSlider.getY() + sliderHeight, driveSlider.getWidth(), 20);
}