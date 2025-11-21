#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainCraftAudioProcessorEditor::GainCraftAudioProcessorEditor (GainCraftAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Set up the slider
    gainSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    gainSlider.setRange(0.0f, 2.0f, 0.01f); // Range from 0.0 to 2.0
    gainSlider.setValue(audioProcessor.gainValue);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);

    // Set the editor size
    setSize (400, 100);
}

GainCraftAudioProcessorEditor::~GainCraftAudioProcessorEditor()
{
}

void GainCraftAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::darkgrey);
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("GainCraft", getLocalBounds(), juce::Justification::centred, 1);
}

void GainCraftAudioProcessorEditor::resized()
{
    gainSlider.setBounds(40, 40, getWidth() - 80, 20);
}

void GainCraftAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.gainValue = slider->getValue(); // Update gain value
    }
}