#include "PluginProcessor.h"
#include "PluginEditor.h"

VelvetSaturationAudioProcessor::VelvetSaturationAudioProcessor()
    : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
      saturationAmount(0.5f), wetLevel(0.5f), dryLevel(0.5f)
{
}

VelvetSaturationAudioProcessor::~VelvetSaturationAudioProcessor() {}

void VelvetSaturationAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) 
{
    // Prepare any resources needed before playback starts
}

void VelvetSaturationAudioProcessor::releaseResources() 
{
    // Release any resources if needed
}

void VelvetSaturationAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) 
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto j = totalNumInputChannels; j < totalNumOutputChannels; ++j)
        buffer.clear (j, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // Apply saturation
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float drySample = channelData[sample];
            float saturatedSample = std::tanh(drySample * saturationAmount);
            channelData[sample] = drySample * dryLevel + saturatedSample * wetLevel;
        }
    }
}

bool VelvetSaturationAudioProcessor::hasEditor() const 
{
    return true; 
}

AudioProcessorEditor* VelvetSaturationAudioProcessor::createEditor() 
{
    return new VelvetSaturationAudioProcessorEditor (*this);
}

const String VelvetSaturationAudioProcessor::getName() const 
{
    return JucePlugin_Name; 
}

bool VelvetSaturationAudioProcessor::acceptsMidi() const 
{
    return false; 
}

bool VelvetSaturationAudioProcessor::producesMidi() const 
{
    return false; 
}

bool VelvetSaturationAudioProcessor::isMidiEffect() const 
{
    return false; 
}

double VelvetSaturationAudioProcessor::getTailLengthSeconds() const 
{
    return 0.0; 
}

int VelvetSaturationAudioProcessor::getNumPrograms() 
{
    return 1; 
}

int VelvetSaturationAudioProcessor::getCurrentProgram() 
{
    return 0; 
}

void VelvetSaturationAudioProcessor::setCurrentProgram (int index) {}

const String VelvetSaturationAudioProcessor::getProgramName (int index) 
{
    return {};
}

void VelvetSaturationAudioProcessor::changeProgramName (int index, const String& newName) {}

void VelvetSaturationAudioProcessor::getStateInformation (MemoryBlock& destData) 
{
    // Store your parameters here
}

void VelvetSaturationAudioProcessor::setStateInformation (const void* data, int sizeInBytes) 
{
    // Retrieve your parameters here
}

// This creates instances of the plugin.
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() 
{
    return new VelvetSaturationAudioProcessor();
}