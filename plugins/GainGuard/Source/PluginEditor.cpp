#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainGuardAudioProcessorEditor::GainGuardAudioProcessorEditor (GainGuardAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Setup the sliders
    inputGainSlider.setRange(0.0f, 2.0f);
    inputGainSlider.setValue(1.0f);
    inputGainSlider.onValueChange = [this] {
        processor.inputGain = inputGainSlider.getValue();
    };
    addAndMakeVisible(inputGainSlider);

    outputGainSlider.setRange(0.0f, 2.0f);
    outputGainSlider.setValue(1.0f);
    outputGainSlider.onValueChange = [this] {
        processor.outputGain = outputGainSlider.getValue();
    };
    addAndMakeVisible(outputGainSlider);

    muteButton.setButtonText("Mute");
    muteButton.onToggleStateChange = [this] {
        processor.isMuted = muteButton.getToggleState();
    };
    addAndMakeVisible(muteButton);

    setSize (400, 200);
}

GainGuardAudioProcessorEditor::~GainGuardAudioProcessorEditor()
{
}

void GainGuardAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::grey);
}

void GainGuardAudioProcessorEditor::resized()
{
    inputGainSlider.setBounds(20, 30, 360, 30);
    outputGainSlider.setBounds(20, 80, 360, 30);
    muteButton.setBounds(20, 130, 360, 30);
}