cmake_minimum_required(VERSION 3.15)
project(LevelLift)

# JUCE CMake settings
set(JUCE_INCLUDE_DIRS "path/to/JUCE/modules" CACHE STRING "JUCE modules path")

# JUCE configuration
set(JUCE_EXTRA_MODULES
    juce_audio_basics
    juce_audio_devices
    juce_audio_formats
    juce_audio_processors
    juce_audio_utils
    juce_core
    juce_data_structures
    juce_gui_basics
    juce_gui_extra
)

include(${JUCE_INCLUDE_DIRS}/JUCE.cmake)

# Create the plugin
juce_add_plugin(LevelLift
    COMPANY_NAME "YourCompany"
    VERSION "1.0.0"
    DESCRIPTION "Level Lift Gain Plugin"
    PLUGIN_TYPE "AudioProcessor"
    FORMATS "VST3"
)

# Add the source files
target_sources(LevelLift PRIVATE
    PluginProcessor.cpp
    PluginProcessor.h
    PluginEditor.cpp
    PluginEditor.h
)

# Link JUCE modules
target_link_libraries(LevelLift PRIVATE
    ${JUCE_EXTRA_MODULES}
)