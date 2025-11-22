cmake_minimum_required(VERSION 3.15)

project(PureTubeGlow VERSION 0.1.0)

# Set JUCE path
set(JUCE_PATH "/path/to/JUCE")  # Change this to your JUCE path

include(${JUCE_PATH}/JUCE.cmake)

juce_add_plugin(PureTubeGlow
    COMPANY_NAME "Your Company"
    PRODUCT_NAME "PureTubeGlow"
    VERSION "0.1.0"
    DESCRIPTION "A clean tube saturator designed to add warmth and depth"
    CATEGORY "Effect"
    TAGS "Saturation"
)

target_sources(PureTubeGlow
    PRIVATE
        PluginProcessor.cpp
        PluginProcessor.h
        PluginEditor.cpp
        PluginEditor.h
)

target_compile_features(PureTubeGlow PRIVATE cxx_std_14)
juce_generate_juce_header(PureTubeGlow)