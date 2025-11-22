#include "PluginEditor.h"

//==============================================================================
PureTubeGlowAudioProcessorEditor::PureTubeGlowAudioProcessorEditor (PureTubeGlowAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    gainSlider = std::make_unique<juce::Slider>("Gain");
    gainSlider->setRange(1.0, 10.0);
    gainSlider->setValue(*processor.parameters.getRawParameterValue("gain"));
    gainSlider->onValueChange = [this] {
        processor.parameters.getParameter("gain")->setValueNotifyingHost(gainSlider->getValue());
    };
    addAndMakeVisible(gainSlider.get());

    gainLabel = std::make_unique<juce::Label>("GainLabel", "Gain");
    addAndMakeVisible(gainLabel.get());

    setSize (400, 300);
}

PureTubeGlowAudioProcessorEditor::~PureTubeGlowAudioProcessorEditor() {}

void PureTubeGlowAudioProcessorEditor::paint (juce::Graphics& g) {
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("PureTubeGlow", getLocalBounds(), juce::Justification::centred, true);
}

void PureTubeGlowAudioProcessorEditor::resized() {
    gainSlider->setBounds (40, 80, 300, 20);
    gainLabel->setBounds (40, 50, 100, 20);
}