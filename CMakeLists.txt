cmake_minimum_required(VERSION 3.15)

project(PlugDropPlugin VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === PATH JUCE CLONÉ PAR GITHUB ACTIONS ===
set(JUCE_PATH "${CMAKE_SOURCE_DIR}/juce")

# === CHARGER LE MODULE JUCE ===
add_subdirectory(${JUCE_PATH})

include(${JUCE_PATH}/extras/Build/CMake/JUCE.cmake)

# === DÉCLARATION DU PLUGIN ===
juce_add_plugin(PlugDropPlugin
    COMPANY_NAME "PlugDrop"
    PLUGIN_MANUFACTURER_CODE Pdro
    PLUGIN_CODE PLGD
    FORMATS VST3
    PRODUCT_NAME "PlugDropPlugin"
)

# === SOURCES ===
target_sources(PlugDropPlugin PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
)

# === LIENS JUCE ===
target_link_libraries(PlugDropPlugin PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_dsp
)
