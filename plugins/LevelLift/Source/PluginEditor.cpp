#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LevelLiftAudioProcessorEditor::LevelLiftAudioProcessorEditor (LevelLiftAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Setup the gain slider
    gainSlider.setSliderStyle (juce::Slider::LinearVertical);
    gainSlider.setRange (-60.0f, 12.0f, 0.1f);
    gainSlider.setValue(0.0f);
    gainSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    gainSlider.setPopupDisplayEnabled(true, false, this);
    gainSlider.setSmoothSlider(true);
    addAndMakeVisible(gainSlider);
    
    gainLabel.setText ("Gain (dB)", juce::dontSendNotification);
    gainLabel.attachToComponent(&gainSlider, true);
    addAndMakeVisible(gainLabel);

    // Attach gain slider to audio processor value tree state
    gainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.parameters,
        "gain",
        gainSlider
    );

    setSize (200, 300);
}

LevelLiftAudioProcessorEditor::~LevelLiftAudioProcessorEditor() {}

void LevelLiftAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(40, 40, 40));
}

void LevelLiftAudioProcessorEditor::resized()
{
    gainSlider.setBounds (40, 40, 120, 200);
}