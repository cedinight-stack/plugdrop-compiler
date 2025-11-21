cmake_minimum_required(VERSION 3.15)

project(ClearCutGate VERSION 1.0.0 LANGUAGES CXX)

set(JUCE_DIR "/path/to/JUCE" CACHE PATH "Path to JUCE")
find_package(JUCE REQUIRED)

juce_add_plugin(ClearCutGate
    COMPANY_NAME "YourCompany"
    VERSION "1.0.0"
    PRODUCT_NAME "ClearCut Gate"
    PLUGIN_TYPE AudioProcessor
)

target_sources(ClearCutGate
    PRIVATE
        PluginProcessor.cpp
        PluginProcessor.h
        PluginEditor.cpp
        PluginEditor.h
)

target_link_libraries(ClearCutGate
    PRIVATE
        JUCE::juce_audio_basics
        JUCE::juce_audio_processors
        JUCE::juce_gui_basics
)

juce_generate_juce_header(ClearCutGate)