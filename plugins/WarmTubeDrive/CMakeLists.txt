cmake_minimum_required(VERSION 3.15)

project(WarmTubeDrive VERSION 0.1.0)

# JUCE Modules
set(JUCE_MODULE_SEARCH_PATH "${PROJECT_SOURCE_DIR}/JUCE/modules")

set(JUCE_MODULES
    juce_core
    juce_events
    juce_gui_basics
    juce_audio_basics
    juce_audio_processors
    juce_audio_utils
)

# Include JUCE
include("${JUCE_MODULE_SEARCH_PATH}/JUCE.cmake")

# Setup target
juce_add_plugin(WarmTubeDrive
    COMPANY_NAME "Your Company"
    PLUGIN_NAME "WarmTubeDrive"
    VERSION "0.1.0"
    DESCRIPTION "A warm tube drive effect"
)

# Add source files
target_sources(WarmTubeDrive PRIVATE
    PluginProcessor.h
    PluginProcessor.cpp
    PluginEditor.h
    PluginEditor.cpp
)

# Link JUCE modules
target_link_libraries(WarmTubeDrive PRIVATE ${JUCE_MODULES})