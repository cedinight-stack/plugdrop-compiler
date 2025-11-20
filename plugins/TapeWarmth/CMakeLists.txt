cmake_minimum_required (VERSION 3.15)

project (TapeWarmth VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 14)

# Include JUCE's cmake modules
if (NOT DEFINED JUCE_INCLUDE_DIR)
    set (JUCE_INCLUDE_DIR "/path/to/JUCE/modules")
endif()

include_directories("${JUCE_INCLUDE_DIR}")

set (JUCE_CMAKE_MODULE "${JUCE_INCLUDE_DIR}/JUCE.cmake")
include (${JUCE_CMAKE_MODULE})

juce_add_plugin (TapeWarmth
    COMPANY_NAME "YourCompany"
    VERSION "0.1.0"
    PRODUCT_NAME "TapeWarmth"
    IS_LIVELY TRUE
    EDITOR_WANTS_KEY_EVENTS TRUE
)

juce_generate_juce_header (TapeWarmth)

target_sources (TapeWarmth PRIVATE
    PluginProcessor.h
    PluginProcessor.cpp
    PluginEditor.h
    PluginEditor.cpp
)

juce_enable_clang_format (TapeWarmth)