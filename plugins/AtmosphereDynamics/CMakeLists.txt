cmake_minimum_required (VERSION 3.15)

project (AtmosphereDynamics VERSION 0.1.0)

# Include JUCE
set(JUCE_DIR "/path/to/JUCE")
set(JUCE_INCLUDE_DIR "${JUCE_DIR}/modules")

include(${JUCE_DIR}/JUCE.cmake)

juce_add_plugin(AtmosphereDynamics
    COMPANY_NAME "Your Company"
    PLUGIN_NAME "AtmosphereDynamics"
    PLUGIN_TYPE AudioProcessor
    FORMATS AU VST3
)

target_sources(AtmosphereDynamics
    PRIVATE
        PluginProcessor.cpp
        PluginEditor.cpp
        PluginProcessor.h
        PluginEditor.h
)

target_link_libraries(AtmosphereDynamics
    PRIVATE
        juce::juce_audio_processors
        juce::juce_audio_basics
)