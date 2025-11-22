cmake_minimum_required(VERSION 3.15)

# Define the project name
project(VelvetGlow VERSION 0.1)

# Define JUCE path
set(JUCE_DIR "<path_to_your_JUCE>")

# Include JUCE
include(${JUCE_DIR}/JUCE.cmake)

# Add the plugin target
juce_add_plugin(VelvetGlow
    COMPANY_NAME "YourCompany"
    VERSION "0.1.0"
    DESCRIPTION "A luxurious warmth saturation plugin"
    PLUGIN_MANUFACTURER_CODE Juce
    PLUGIN_CODE VGlow
    PROCESSES_AUDIO TRUE
)

# Add plugin source files
target_sources(VelvetGlow PRIVATE
    PluginProcessor.h
    PluginProcessor.cpp
    PluginEditor.h
    PluginEditor.cpp
)

# Link JUCE modules
target_link_juce_modules(VelvetGlow
    juce_core
    juce_engine
    juce_gui_basics
)