cmake_minimum_required(VERSION 3.15)

project(PrecisionBoost)

set(JUCE_DIR "path/to/JUCE")  # Update this to where your JUCE is located

include(${JUCE_DIR}/JUCE.cmake)

juce_add_plugin(PrecisionBoost
    COMPANY_NAME "YourCompany"
    PLUGIN_NAME "PrecisionBoost"
    PLUGIN_VERSION "1.0.0"
    PLUGIN_TYPE Effect
    PLUGIN_HAS_EDITOR TRUE
    PLUGIN_EDITOR_HAS_DEFAULT_HEADER TRUE
)

target_sources(PrecisionBoost
    PRIVATE
        PluginProcessor.cpp
        PluginEditor.cpp
        PluginProcessor.h
        PluginEditor.h
)

target_compile_definitions(PrecisionBoost PRIVATE JUCE_PLUGINNAME_STRING="PrecisionBoost")