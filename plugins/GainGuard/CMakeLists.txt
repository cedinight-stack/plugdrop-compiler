cmake_minimum_required(VERSION 3.15)

project(GainGuard VERSION 1.0.0)

# JUCE
set(JUCE_DIR "path/to/juce")  # Change this to your JUCE path
set(CMAKE_MODULE_PATH "${JUCE_DIR}/Modules" ${CMAKE_MODULE_PATH})

add_subdirectory(${JUCE_DIR} JUCE)

juce_add_plugin(GainGuard
    COMPANY_NAME "YourCompanyName"
    PRODUCT_NAME "GainGuard"
    VERSION "$PROJECT_VERSION"
    DESCRIPTION "A simple gain plugin with input volume, output volume, and a mute button."
    CLASS_NAME GainGuardAudioProcessor
    EDITOR_CLASS_NAME GainGuardAudioProcessorEditor
)

target_sources(GainGuard
    PRIVATE
        PluginProcessor.cpp
        PluginProcessor.h
        PluginEditor.cpp
        PluginEditor.h
)

target_link_libraries(GainGuard
    PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_processors
        juce::juce_gui_basics
)