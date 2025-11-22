#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WarmthWaveAudioProcessor::WarmthWaveAudioProcessor()
    : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
      parameters(*this, nullptr)
{
    parameters.createAndAddParameter("saturation", "Saturation", "Amount of saturation to apply",
                                       juce::NormalisableRange<float>(0.0f, 1.0f), 0.5f,
                                       nullptr, nullptr);
    parameters.state = juce::ValueTree("savedParams");
}

WarmthWaveAudioProcessor::~WarmthWaveAudioProcessor() {}

void WarmthWaveAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) 
{
    saturationAmount = *parameters.getRawParameterValue("saturation");
}

void WarmthWaveAudioProcessor::releaseResources() {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool WarmthWaveAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}
#endif

void WarmthWaveAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear the output channels
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // Apply saturation
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            // Apply simple soft clipping
            float sampleValue = channelData[sample];

            // Simple saturation algorithm
            sampleValue = std::tanh(sampleValue * saturationAmount);
            channelData[sample] = sampleValue;
        }
    }
}

juce::AudioProcessorEditor* WarmthWaveAudioProcessor::createEditor() 
{
    return new WarmthWaveAudioProcessorEditor (*this);
}

bool WarmthWaveAudioProcessor::hasEditor() const 
{
    return true; 
}