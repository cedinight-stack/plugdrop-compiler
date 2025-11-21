cmake_minimum_required(VERSION 3.15)

project(GateKeeper VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

include(JUCE)

juce_add_plugin(GateKeeper
    COMPANY_NAME "YourCompany"
    PRODUCT_NAME "GateKeeper"
    VERSION "0.1.0"
    IS_GUI TRUE
    IS_FX TRUE
    NEEDS_AUDIO_PLUGIN TRUE
    CLASS_PREFIX "GateKeeper"
)

target_sources(GateKeeper
    PRIVATE
        PluginProcessor.cpp
        PluginEditor.cpp
        PluginProcessor.h
        PluginEditor.h
)

juce_generate_juce_header(GateKeeper)