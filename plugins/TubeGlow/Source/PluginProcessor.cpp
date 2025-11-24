#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TubeGlowAudioProcessor::TubeGlowAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
 : AudioProcessor (BusesProperties().withInput ("Input", juce::AudioChannelSet::stereo(), true)
                      .withOutput ("Output", juce::AudioChannelSet::stereo(), true))
#endif
{
    gainParameter = 1.0f; // Default gain
    mixParameter = 0.5f;  // Default mix (50% wet)
}

TubeGlowAudioProcessor::~TubeGlowAudioProcessor()
{
}

void TubeGlowAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Prepare any resources needed before playback
}

void TubeGlowAudioProcessor::releaseResources()
{
    // Release any resources when playback stops
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TubeGlowAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}
#endif

void TubeGlowAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear output channels if input is less than output
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        // Apply tube saturation algorithm
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            float inputSample = channelData[sample];

            // Simple saturation logic
            float outputSample = juce::jlimit(-1.0f, 1.0f, inputSample * gainParameter);
            outputSample = (outputSample > 0.0f) ? (outputSample - (outputSample * outputSample * outputSample) * 0.5f) 
                                                  : (outputSample + (outputSample * outputSample * outputSample) * 0.5f);
            channelData[sample] = inputSample * (1 - mixParameter) + outputSample * mixParameter;
        }
    }
}

juce::AudioProcessorEditor* TubeGlowAudioProcessor::createEditor()
{
    return new TubeGlowAudioProcessorEditor (*this);
}

void TubeGlowAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // Store parameters to the MemoryBlock
    auto state = juce::ValueTree ("TubeGlowState");
    state.setProperty ("gain", gainParameter, nullptr);
    state.setProperty ("mix", mixParameter, nullptr);
    juce::MemoryOutputStream stream (destData, true);
    juce::JSON::toString (state, stream);
}

void TubeGlowAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    auto state = juce::JSON::fromString (juce::String ((const char*) data, sizeInBytes));
    gainParameter = state.getProperty("gain", 1.0f);
    mixParameter = state.getProperty("mix", 0.5f);
}