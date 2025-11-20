#include "PluginProcessor.h"
#include "PluginEditor.h"

AtmosphereDynamicsAudioProcessorEditor::AtmosphereDynamicsAudioProcessorEditor (AtmosphereDynamicsAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Setup sliders for the parameters
    thresholdSlider.setSliderStyle(juce::Slider::LinearVertical);
    thresholdSlider.setRange(-60.0f, 0.0f);
    thresholdSlider.setValue(-20.0f);
    thresholdSlider.setTextValueSuffix(" dB");
    addAndMakeVisible(thresholdSlider);
    
    ratioSlider.setSliderStyle(juce::Slider::LinearVertical);
    ratioSlider.setRange(1.0f, 20.0f);
    ratioSlider.setValue(4.0f);
    addAndMakeVisible(ratioSlider);
    
    attackSlider.setSliderStyle(juce::Slider::LinearVertical);
    attackSlider.setRange(0.1f, 200.0f);
    attackSlider.setValue(10.0f);
    attackSlider.setTextValueSuffix(" ms");
    addAndMakeVisible(attackSlider);
    
    releaseSlider.setSliderStyle(juce::Slider::LinearVertical);
    releaseSlider.setRange(1.0f, 2000.0f);
    releaseSlider.setValue(100.0f);
    releaseSlider.setTextValueSuffix(" ms");
    addAndMakeVisible(releaseSlider);
    
    makeUpGainSlider.setSliderStyle(juce::Slider::LinearVertical);
    makeUpGainSlider.setRange(0.0f, 12.0f);
    makeUpGainSlider.setValue(0.0f);
    makeUpGainSlider.setTextValueSuffix(" dB");
    addAndMakeVisible(makeUpGainSlider);

    // Creating labels
    thresholdLabel.setText("Threshold", juce::dontSendNotification);
    addAndMakeVisible(thresholdLabel);
    
    ratioLabel.setText("Ratio", juce::dontSendNotification);
    addAndMakeVisible(ratioLabel);
    
    attackLabel.setText("Attack", juce::dontSendNotification);
    addAndMakeVisible(attackLabel);
    
    releaseLabel.setText("Release", juce::dontSendNotification);
    addAndMakeVisible(releaseLabel);
    
    makeUpGainLabel.setText("Make Up Gain", juce::dontSendNotification);
    addAndMakeVisible(makeUpGainLabel);
    
    setSize (300, 400);
}

AtmosphereDynamicsAudioProcessorEditor::~AtmosphereDynamicsAudioProcessorEditor()
{
}

void AtmosphereDynamicsAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::lightgrey);
}

void AtmosphereDynamicsAudioProcessorEditor::resized()
{
    auto area = getLocalBounds().reduced(10);
    auto sliderWidth = 50;
    auto sliderHeight = 200;

    thresholdSlider.setBounds(area.removeFromLeft(sliderWidth).withHeight(sliderHeight));
    ratioSlider.setBounds(area.removeFromLeft(sliderWidth).withHeight(sliderHeight));
    attackSlider.setBounds(area.removeFromLeft(sliderWidth).withHeight(sliderHeight));
    releaseSlider.setBounds(area.removeFromLeft(sliderWidth).withHeight(sliderHeight));
    makeUpGainSlider.setBounds(area.removeFromLeft(sliderWidth).withHeight(sliderHeight));
    
    thresholdLabel.setBounds(thresholdSlider.getX(), thresholdSlider.getY() + sliderHeight + 5, sliderWidth, 20);
    ratioLabel.setBounds(ratioSlider.getX(), ratioSlider.getY() + sliderHeight + 5, sliderWidth, 20);
    attackLabel.setBounds(attackSlider.getX(), attackSlider.getY() + sliderHeight + 5, sliderWidth, 20);
    releaseLabel.setBounds(releaseSlider.getX(), releaseSlider.getY() + sliderHeight + 5, sliderWidth, 20);
    makeUpGainLabel.setBounds(makeUpGainSlider.getX(), makeUpGainSlider.getY() + sliderHeight + 5, sliderWidth, 20);
}