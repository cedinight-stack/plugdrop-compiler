#include "PluginProcessor.h"
#include "PluginEditor.h"

GateKeeperAudioProcessorEditor::GateKeeperAudioProcessorEditor (GateKeeperAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    thresholdSlider.setRange(-60.0f, 0.0f);
    thresholdSlider.setValue(processor.getThreshold());
    thresholdSlider.onValueChange = [this] { processor.setThreshold(thresholdSlider.getValue()); };
    addAndMakeVisible(thresholdSlider);

    thresholdLabel.setText("Threshold (dB)", juce::dontSendNotification);
    addAndMakeVisible(thresholdLabel);

    releaseTimeSlider.setRange(1.0f, 5000.0f);
    releaseTimeSlider.setValue(processor.getReleaseTime());
    releaseTimeSlider.onValueChange = [this] { processor.setReleaseTime(releaseTimeSlider.getValue()); };
    addAndMakeVisible(releaseTimeSlider);

    releaseTimeLabel.setText("Release Time (ms)", juce::dontSendNotification);
    addAndMakeVisible(releaseTimeLabel);

    setSize (400, 200);
}

GateKeeperAudioProcessorEditor::~GateKeeperAudioProcessorEditor() {}

void GateKeeperAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void GateKeeperAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    thresholdSlider.setBounds (bounds.removeFromTop(40).reduced(20));
    thresholdLabel.setBounds (thresholdSlider.getX(), thresholdSlider.getY() - 20, thresholdSlider.getWidth(), 20);

    releaseTimeSlider.setBounds (bounds.removeFromTop(40).reduced(20));
    releaseTimeLabel.setBounds (releaseTimeSlider.getX(), releaseTimeSlider.getY() - 20, releaseTimeSlider.getWidth(), 20);
}