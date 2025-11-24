cmake_minimum_required(VERSION 3.15)

project(TubeGlow VERSION 0.1.0)

# JUCE
# You must specify the path to your JUCE modules
set(JUCE_DIR "/path/to/JUCE")

# JUCE modules
set(JUCE_MODULES_DIR "${JUCE_DIR}/modules")
include_directories(${JUCE_MODULES_DIR})

set(CMAKE_MODULE_PATH "${JUCE_DIR}")

# Include JUCE's CMake functions
include (${JUCE_DIR}/JUCE.cmake)

# Create the plugin's main target
juce_add_plugin(TubeGlow
    COMPANY_NAME "Your Company"
    VERSION "0.1.0"
    PRODUCT_NAME "TubeGlow"
    PLUGIN_DESCRIPTION "Emulate the warm, rich harmonics of vintage tube amplifiers."
    PLUGIN_MFR "Your Company"
    PLUGIN_MFR_URL "http://yourcompany.com"
    PLUGIN_MFR_EMAIL "info@yourcompany.com"
    PLUGIN_TYPE "audio_processor"
    CREATOR_TYPE "audio_processor"
)

# Add sources
target_sources(TubeGlow PRIVATE
    PluginProcessor.cpp
    PluginEditor.cpp
)

# Link JUCE modules
target_link_libraries(TubeGlow PRIVATE
    juce_core
    juce_audio_basics
    juce_audio_processors
    juce_gui_basics
)