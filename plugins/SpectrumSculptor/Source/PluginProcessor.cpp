#include "PluginProcessor.h"

//==============================================================================
SpectrumSculptorAudioProcessor::SpectrumSculptorAudioProcessor()
    : parameters(*this, nullptr, juce::Identifier("SpectrumSculptor"),
                {
                    std::make_unique<juce::AudioParameterFloat>("gain", "Gain", -12.0f, 12.0f, 0.0f),
                    std::make_unique<juce::AudioParameterFloat>("frequency", "Frequency", 20.0f, 20000.0f, 1000.0f),
                    std::make_unique<juce::AudioParameterFloat>("q", "Q", 0.1f, 20.0f, 1.0f)
                })
{
}

SpectrumSculptorAudioProcessor::~SpectrumSculptorAudioProcessor()
{
}

void SpectrumSculptorAudioProcessor::prepareToPlay (double newSampleRate, int samplesPerBlock)
{
    sampleRate = newSampleRate;
    filter = std::make_unique<juce::dsp::Processor<juce::dsp::IIR::Filter<float>>>();
}

void SpectrumSculptorAudioProcessor::releaseResources()
{
    filter.reset();
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SpectrumSculptorAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    return true; // Here you could implement more complex layout checks
}
#endif

void SpectrumSculptorAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    auto gain = *parameters.getRawParameterValue("gain");
    auto frequency = *parameters.getRawParameterValue("frequency");
    auto q = *parameters.getRawParameterValue("q");

    // Set up the filter parameters dynamically
    filter->setCoefficients(juce::dsp::IIR::Coefficients<float>::makePeakFilter(sampleRate, frequency, q, juce::Maths::pow(10.0f, gain / 20.0f)));

    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);
        filter->processMono(channelData, buffer.getNumSamples());
    }
}