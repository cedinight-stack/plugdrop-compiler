#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VelvetGlowAudioProcessor::VelvetGlowAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true))
#endif
{
    addParameter(saturationAmount = new juce::AudioParameterFloat("saturation", "Saturation", 0.0f, 1.0f, 0.5f));
    addParameter(outputGain = new juce::AudioParameterFloat("outputGain", "Output Gain", -12.0f, 12.0f, 0.0f));
}

VelvetGlowAudioProcessor::~VelvetGlowAudioProcessor() {}

void VelvetGlowAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) {
    // Prepare the processor for playback
}

void VelvetGlowAudioProcessor::releaseResources() {
    // Free up resources
}

bool VelvetGlowAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const {
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}

void VelvetGlowAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) {
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    float saturation = saturationAmount->getValue();
    float gain = juce::Decibels::decibelsToGain(outputGain->getValue());

    for (int channel = 0; channel < totalNumInputChannels; ++channel) {
        auto* channelData = buffer.getWritePointer (channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
            float inputSample = channelData[sample];

            // Apply simple saturation effect
            float saturatedSample = std::tanh(saturation * inputSample);
            channelData[sample] = saturatedSample * gain;
        }
    }
}

juce::AudioProcessorEditor* VelvetGlowAudioProcessor::createEditor() {
    return new VelvetGlowAudioProcessorEditor (*this);
}

void VelvetGlowAudioProcessor::getStateInformation (juce::MemoryBlock& destData) {
    // Store parameters here
    juce::MemoryOutputStream stream(destData, true);
    stream.writeFloat(saturationAmount->getValue());
    stream.writeFloat(outputGain->getValue());
}

void VelvetGlowAudioProcessor::setStateInformation (const void* data, int sizeInBytes) {
    // Restore parameters here
    const float* parameters = static_cast<const float*>(data);
    saturationAmount->setValue(parameters[0]);
    outputGain->setValue(parameters[1]);
}

// This creates the instance of the plugin
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new VelvetGlowAudioProcessor();
}