cmake_minimum_required(VERSION 3.15)

project(SmoothSaturate LANGUAGES CXX)

set(JUCE_DIR "/path/to/JUCE")  # Change this to your JUCE path

set(CMAKE_CURRENT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Source")
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/PluginProcessor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PluginProcessor.h
    ${CMAKE_CURRENT_SOURCE_DIR}/PluginEditor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PluginEditor.h
)

set(JUCE_ENVIRONMENT_PATH "${JUCE_DIR}/JUCE")

include(JuceCabinet)

juce_add_plugin(SmoothSaturate
    COMPANY_NAME "YourCompany"
    VERSION "0.1.0"
    IS_AUDIO_EFFECT true
    INPUT_CHANNELS  2
    OUTPUT_CHANNELS 2
)

target_sources(SmoothSaturate PRIVATE ${SOURCES})