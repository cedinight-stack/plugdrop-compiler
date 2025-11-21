cmake_minimum_required(VERSION 3.15)

project(GainCraft VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

# JUCE path (change to your JUCE path)
set(JUCE_PATH "/path/to/JUCE")

list(APPEND CMAKE_MODULE_PATH "${JUCE_PATH}/JUCE/modules")

# JUCE
find_package(JUCE REQUIRED CONFIG)

juce_add_plugin(GainCraft
    VERSION ${PROJECT_VERSION}
    COMPANY_NAME "YourCompany"
    LICENSE "YourLicense"
    DESCRIPTION "A simple gain plugin."
    CLASSID "12345678-1234-1234-1234-123456789abc"
    PIPENAME "GainCraft"
)

target_sources(GainCraft
    PRIVATE
        PluginProcessor.cpp
        PluginProcessor.h
        PluginEditor.cpp
        PluginEditor.h
)

juce_generate_juce_header(GainCraft)

target_link_libraries(GainCraft
    PRIVATE
        JUCE::JUCE_audio_utils
        JUCE::JUCE_audio_processors
        JUCE::JUCE_gui_basics
)