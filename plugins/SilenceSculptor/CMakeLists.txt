cmake_minimum_required (VERSION 3.15)

project (SilenceSculptor VERSION 1.0.0)

set (JUCE_DIR "path/to/JUCE") # Adjust this to your JUCE path

include (${JUCE_DIR}/JUCE.cmake)

juce_add_plugin(SilenceSculptor
    COMPANY_NAME "YourCompany"
    PRODUCT_NAME "SilenceSculptor"
    VERSION ${PROJECT_VERSION}
    DESCRIPTION "Streamlined Noise Gate Plugin"
    PLUGIN_MANUFACTURER_CODE Juce
    PLUGIN_CODE SlsC
    FORMATS PluginFormatAAX PluginFormatAU PluginFormatVST3
)

target_sources(SilenceSculptor PRIVATE
    PluginProcessor.cpp
    PluginEditor.cpp
)

target_compile_features(SilenceSculptor PRIVATE cxx_std_17)

juce_generate_juce_header(SilenceSculptor)