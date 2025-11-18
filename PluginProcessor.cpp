#include "PluginProcessor.h"

SimplePluginAudioProcessor::SimplePluginAudioProcessor() {}
SimplePluginAudioProcessor::~SimplePluginAudioProcessor() {}

void SimplePluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock) {}
void SimplePluginAudioProcessor::releaseResources() {}

void SimplePluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                               juce::MidiBuffer&) 
{
    // Basic passthrough
}
