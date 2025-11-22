cmake_minimum_required(VERSION 3.15)

project(VelvetSaturation VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

include(JUCE)

juce_add_plugin(VelvetSaturation
    COMPANY_NAME "YourCompany"
    PLUGIN_NAME "VelvetSaturation"
    PLUGIN_TYPE AudioProcessor
    VERSION "0.1.0"
)

target_sources(VelvetSaturation
    PRIVATE
        PluginProcessor.cpp
        PluginEditor.cpp
        PluginProcessor.h
        PluginEditor.h
)

juce_generate_juce_header(VelvetSaturation)