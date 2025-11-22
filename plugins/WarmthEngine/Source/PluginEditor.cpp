#include "PluginEditor.h"

WarmthEngineAudioProcessorEditor::WarmthEngineAudioProcessorEditor (WarmthEngineAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Slider setup
    saturationSlider.setSliderStyle(juce::Slider::LinearVertical);
    saturationSlider.setRange(0.0, 1.0);
    saturationSlider.setValue(audioProcessor.getSaturationLevel());
    saturationSlider.onValueChange = [this] { audioProcessor.setSaturationLevel(saturationSlider.getValue()); };
    addAndMakeVisible(saturationSlider);

    dryWetSlider.setSliderStyle(juce::Slider::LinearVertical);
    dryWetSlider.setRange(0.0, 1.0);
    dryWetSlider.setValue(audioProcessor.getDryWet());
    dryWetSlider.onValueChange = [this] { audioProcessor.setDryWet(dryWetSlider.getValue()); };
    addAndMakeVisible(dryWetSlider);

    setSize (400, 300);
}

WarmthEngineAudioProcessorEditor::~WarmthEngineAudioProcessorEditor() = default;

void WarmthEngineAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.drawFittedText ("WarmthEngine Saturator", getLocalBounds(), juce::Justification::centredTop, 1);
}

void WarmthEngineAudioProcessorEditor::resized()
{
    saturationSlider.setBounds(50, 50, 80, 200);
    dryWetSlider.setBounds(150, 50, 80, 200);
}