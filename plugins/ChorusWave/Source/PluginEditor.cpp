#include "PluginEditor.h"

//==============================================================================
ChorusWaveAudioProcessorEditor::ChorusWaveAudioProcessorEditor(ChorusWaveAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Rate Slider
    rateSlider.setSliderStyle(juce::Slider::LinearVertical);
    rateSlider.setRange(0.1f, 10.0f);
    rateSlider.setValue(*audioProcessor.parameters.getRawParameterValue("rate"));
    rateSlider.setTextValueSuffix(" Hz");
    rateSlider.onValueChange = [this] {
        *audioProcessor.parameters.getRawParameterValue("rate") = rateSlider.getValue();
    };

    addAndMakeVisible(rateSlider);

    // Depth Slider
    depthSlider.setSliderStyle(juce::Slider::LinearVertical);
    depthSlider.setRange(0.f, 1.f);
    depthSlider.setValue(*audioProcessor.parameters.getRawParameterValue("depth"));
    depthSlider.setTextValueSuffix(" %");
    depthSlider.onValueChange = [this] {
        *audioProcessor.parameters.getRawParameterValue("depth") = depthSlider.getValue();
    };

    addAndMakeVisible(depthSlider);

    // Labels
    rateLabel.setText("Rate", juce::dontSendNotification);
    depthLabel.setText("Depth", juce::dontSendNotification);

    addAndMakeVisible(rateLabel);
    addAndMakeVisible(depthLabel);

    setSize(300, 400);
}

ChorusWaveAudioProcessorEditor::~ChorusWaveAudioProcessorEditor() {}

void ChorusWaveAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void ChorusWaveAudioProcessorEditor::resized()
{
    auto area = getLocalBounds();
    rateSlider.setBounds(area.removeFromLeft(100).reduced(20));
    depthSlider.setBounds(area.removeFromLeft(100).reduced(20));
    rateLabel.setBounds(rateSlider.getX(), rateSlider.getY() - 20, 100, 20);
    depthLabel.setBounds(depthSlider.getX(), depthSlider.getY() - 20, 100, 20);
}