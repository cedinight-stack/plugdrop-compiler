#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WarmTubeDriveAudioProcessor::WarmTubeDriveAudioProcessor()
    : AudioProcessor (BusesProperties().withOutput ("Output", juce::AudioChannelSet::stereo(), true)),
      parameters (*this, nullptr) // Initialize parameter state
{
    // Create parameters
    parameters.createAndAddParameter("gain", "Gain", "Gain", 
        juce::NormalisableRange<float>(0.0f, 10.0f), 1.0f, nullptr, nullptr);
    
    parameters.createAndAddParameter("drive", "Drive", "Drive",
        juce::NormalisableRange<float>(0.0f, 1.0f), 0.5f, nullptr, nullptr);

    parameters.state = juce::ValueTree("savedParams");
}

WarmTubeDriveAudioProcessor::~WarmTubeDriveAudioProcessor()
{
}

void WarmTubeDriveAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void WarmTubeDriveAudioProcessor::releaseResources()
{
}

void WarmTubeDriveAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    // Get current parameter values
    gain = *parameters.getRawParameterValue("gain");
    drive = *parameters.getRawParameterValue("drive");

    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            // Simple tube saturation algorithm
            float inputSample = channelData[sample];
            float processedSample = gain * inputSample;

            // Apply tube drive using soft clipping
            processedSample = (1.0f - std::exp(-drive * processedSample)) / (1.0f + std::abs(processedSample));

            channelData[sample] = processedSample;
        }
    }
}

bool WarmTubeDriveAudioProcessor::hasEditor() const
{
    return true; 
}

juce::AudioProcessorEditor* WarmTubeDriveAudioProcessor::createEditor()
{
    return new WarmTubeDriveAudioProcessorEditor (*this);
}

const juce::String WarmTubeDriveAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool WarmTubeDriveAudioProcessor::acceptsMidi() const { return false; }
bool WarmTubeDriveAudioProcessor::producesMidi() const { return false; }
bool WarmTubeDriveAudioProcessor::isMidiEffect() const { return false; }
double WarmTubeDriveAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int WarmTubeDriveAudioProcessor::getNumPrograms() { return 1; }
int WarmTubeDriveAudioProcessor::getCurrentProgram() { return 0; }
void WarmTubeDriveAudioProcessor::setCurrentProgram (int index) {}
const juce::String WarmTubeDriveAudioProcessor::getProgramName (int index) { return {}; }
void WarmTubeDriveAudioProcessor::changeProgramName (int index, const juce::String& newName) {}

void WarmTubeDriveAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // Save current state
    juce::MemoryOutputStream stream (destData, true);
    parameters.state.writeToStream (stream);
}

void WarmTubeDriveAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // Load state
    juce::MemoryInputStream stream (data, sizeInBytes, false);
    parameters.state = juce::ValueTree::readFromStream (stream);
}