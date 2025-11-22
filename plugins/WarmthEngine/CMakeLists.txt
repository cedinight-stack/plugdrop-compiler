cmake_minimum_required(VERSION 3.15)

project(WarmthEngine)

set(CMAKE_CXX_STANDARD 14)

include(GNUInstallDirs)

# JUCE
set(JUCE_DIR "path_to_your_juce_folder")
find_package(JUCE REQUIRED)

juce_add_plugin(WarmthEngine
    COMPANY_NAME "YourCompany"
    VERSION "1.0.0"
    PLUGIN_TYPE BusesProcessor
    PLUGIN_URI "com.yourcompany.warmthengine"
    COPY_ON_INSTALL TRUE
)

target_sources(WarmthEngine PRIVATE
    PluginProcessor.cpp
    PluginProcessor.h
    PluginEditor.cpp
    PluginEditor.h
)

target_link_libraries(WarmthEngine PRIVATE JUCE::JUCEAudioPlugin)