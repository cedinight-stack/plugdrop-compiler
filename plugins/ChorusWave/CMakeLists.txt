cmake_minimum_required(VERSION 3.15)

project(ChorusWave VERSION 0.1.0)

# JUCE
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/JUCE/modules)
find_package(JUCE REQUIRED)

set (CMAKE_CXX_STANDARD 14)

# Add Source Files
set(SRCS
    PluginProcessor.cpp
    PluginEditor.cpp
    PluginProcessor.h
    PluginEditor.h
)

juce_add_plugin(ChorusWave
    COMPANY_NAME "YourCompany"
    VERSION_MAJOR 1
    VERSION_MINOR 0
    VERSION_STRING "${PROJECT_VERSION}"
    DESCRIPTION "A lush chorus effect"
    PLUGIN_MANUFACTURER_CODE Juce
    PLUGIN_CODE ChWv
    FORMATS AU VST3
)

target_sources(ChorusWave PRIVATE ${SRCS})

juce_generate_juce_header(ChorusWave)
target_link_libraries(ChorusWave PRIVATE JUCE::JUCE)