cmake_minimum_required(VERSION 3.15)

project(PlugDropPlugin)

set(CMAKE_CXX_STANDARD 17)

set(JUCE_DIR "/root/juce")

add_subdirectory("${JUCE_DIR}")

juce_add_plugin(${PLUGIN_NAME}
    VERSION "1.0.0"
    COMPANY_NAME "PlugDrop"
    FORMATS VST3 AU AAX
    PRODUCT_NAME ${PLUGIN_NAME}
)

target_sources(${PLUGIN_NAME} PRIVATE
    PluginProcessor.cpp
    PluginEditor.cpp
)

target_link_libraries(${PLUGIN_NAME} PRIVATE
    juce::juce_audio_utils
    juce::juce_dsp
)
