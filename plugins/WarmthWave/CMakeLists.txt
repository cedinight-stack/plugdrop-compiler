cmake_minimum_required(VERSION 3.15)

project(WarmthWave)

set(CMAKE_CXX_STANDARD 14)

# JUCE module
set(JUCE_MODULE_PATH "path/to/JUCE/modules")

# Add JUCE Modules
include(${JUCE_MODULE_PATH}/JUCE.cmake)

juce_add_plugin(WarmthWave
    COMPANY_NAME "Your Company"
    VERSION "1.0.0"
    PLUGIN_NAME "WarmthWave"
    PLUGIN_DESCRIPTION "Injects analog warmth and harmonic distortion."
    PLUGIN_CONTRACT_IDS JucePlugin_Version
    PLUGIN_CATEGORY "Effect"
    PLUGIN_CLASS_NAME "WarmthWaveAudioProcessor"
)

# Include source files
target_sources(WarmthWave PRIVATE
    PluginProcessor.cpp
    PluginProcessor.h
    PluginEditor.cpp
    PluginEditor.h
)

target_link_libraries(WarmthWave PRIVATE juce::juce_audio_basics juce::juce_audio_processors)