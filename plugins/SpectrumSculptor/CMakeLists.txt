cmake_minimum_required(VERSION 3.15)

project(SpectrumSculptor VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set JUCE_ROOT to the path where JUCE is located
set(JUCE_ROOT "/path/to/JUCE/")

# Include JUCE
include("${JUCE_ROOT}/CMakeLists.txt")

# Define the plugin
juce_add_plugin(SpectrumSculptor
    COMPANY_NAME "YourCompany"
    PRODUCT_NAME "Spectrum Sculptor"
    IS_A_PLUGIN TRUE
    VERSION "0.1.0"
    DESCRIPTION "A dynamic equalizer that intelligently adapts to your audio signal."
    COPY_FILES_TO_BINARY_DIR ON
)

# Source files
target_sources(SpectrumSculptor
    PRIVATE
        PluginProcessor.h
        PluginProcessor.cpp
        PluginEditor.h
        PluginEditor.cpp
)

# Link JUCE modules
juce_use_modules(SpectrumSculptor
    juce_core
    juce_gui_basics
    juce_dsp
)