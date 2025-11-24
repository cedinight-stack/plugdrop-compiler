#include "PluginEditor.h"

//==============================================================================
SpectrumSculptorAudioProcessorEditor::SpectrumSculptorAudioProcessorEditor (SpectrumSculptorAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(juce::Slider::LinearVertical);
    gainSlider.setRange(-12.0f, 12.0f, 0.1f);
    gainSlider.setValue(0.0f);
    gainSlider.setTextValueSuffix(" dB");
    addAndMakeVisible(gainSlider);

    frequencySlider.setSliderStyle(juce::Slider::LinearVertical);
    frequencySlider.setRange(20.0f, 20000.0f, 1.0f);
    frequencySlider.setValue(1000.0f);
    frequencySlider.setTextValueSuffix(" Hz");
    addAndMakeVisible(frequencySlider);

    qSlider.setSliderStyle(juce::Slider::LinearVertical);
    qSlider.setRange(0.1f, 20.0f, 0.1f);
    qSlider.setValue(1.0f);
    addAndMakeVisible(qSlider);

    setSize (400, 300);
}

SpectrumSculptorAudioProcessorEditor::~SpectrumSculptorAudioProcessorEditor()
{
}

void SpectrumSculptorAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
    g.setColour (juce::Colours::white);
    g.drawFittedText("Spectrum Sculptor", getLocalBounds(), juce::Justification::centred, 1);
}

void SpectrumSculptorAudioProcessorEditor::resized()
{
    int sliderWidth = 50;
    int sliderHeight = getHeight() - 60;

    gainSlider.setBounds(10, 10, sliderWidth, sliderHeight);
    frequencySlider.setBounds(70, 10, sliderWidth, sliderHeight);
    qSlider.setBounds(130, 10, sliderWidth, sliderHeight);
}