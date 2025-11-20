#include "PluginProcessor.h"
#include "PluginEditor.h"

AtmosphereDynamicsAudioProcessor::AtmosphereDynamicsAudioProcessor()
    : AudioProcessor (BusesProperties().withOutput ("Output",  juce::AudioChannelSet::stereo(), true)),
      parameters(*this, nullptr, "PARAMETERS", 
                 {
                     std::make_unique<juce::AudioParameterFloat>("threshold", "Threshold", -60.0f, 0.0f, -20.0f),
                     std::make_unique<juce::AudioParameterFloat>("ratio", "Ratio", 1.0f, 20.0f, 4.0f),
                     std::make_unique<juce::AudioParameterFloat>("attack", "Attack", 0.1f, 200.0f, 10.0f),
                     std::make_unique<juce::AudioParameterFloat>("release", "Release", 1.0f, 2000.0f, 100.0f),
                     std::make_unique<juce::AudioParameterFloat>("makeUpGain", "Make Up Gain", 0.0f, 12.0f, 0.0f)
                 }),
      threshold(parameters.getRawParameterValue("threshold")),
      ratio(parameters.getRawParameterValue("ratio")),
      attack(parameters.getRawParameterValue("attack")),
      release(parameters.getRawParameterValue("release")),
      makeUpGain(parameters.getRawParameterValue("makeUpGain"))
{
}

AtmosphereDynamicsAudioProcessor::~AtmosphereDynamicsAudioProcessor() 
{
}

void AtmosphereDynamicsAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    // Prepare any DSP-related resources here
}

void AtmosphereDynamicsAudioProcessor::releaseResources() 
{
    // Release any DSP-related resources here
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AtmosphereDynamicsAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    // Only supporting stereo output
    return (layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo());
}
#endif

void AtmosphereDynamicsAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    float attackTime = *attack;
    float releaseTime = *release;
    float inputThreshold = juce::Decibels::decibelsToGain(*threshold);
    float compressionRatio = *ratio;
    float makeUpGainFactor = juce::Decibels::decibelsToGain(*makeUpGain);
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getPointer(channel);
        
        // Simple compression algorithm
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float input = channelData[sample];
            float gain = 1.0f;
            
            if (input > inputThreshold)
            {
                gain = inputThreshold + (input - inputThreshold) / compressionRatio;
            }
            
            channelData[sample] *= gain * makeUpGainFactor;
        }
    }
}

void AtmosphereDynamicsAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    juce::MemoryOutputStream stream(destData, true);
    parameters.state.writeToStream(stream);
}

void AtmosphereDynamicsAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    juce::MemoryInputStream stream(data, sizeInBytes, false);
    parameters.state.readFromStream(stream);
}

juce::AudioProcessorEditor* AtmosphereDynamicsAudioProcessor::createEditor()
{
    return new AtmosphereDynamicsAudioProcessorEditor(*this);
}

bool AtmosphereDynamicsAudioProcessor::hasEditor() const
{
    return true; // This plugin has a GUI
}