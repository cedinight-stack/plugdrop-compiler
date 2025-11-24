cmake_minimum_required(VERSION 3.15)

# Nom du plugin : il doit correspondre au nom du fichier
set(PLUGIN_NAME "PlugDropPlugin")

project(${PLUGIN_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Chemin vers JUCE – GitHub Actions le clone dans ../juce
set(JUCE_PATH "${CMAKE_SOURCE_DIR}/../juce")

# Ajout de JUCE au projet
add_subdirectory(${JUCE_PATH} juce)

# Déclaration du plugin
juce_add_plugin(${PLUGIN_NAME}
    VERSION "1.0.0"
    COMPANY_NAME "PlugDrop"
    PLUGIN_MANUFACTURER_CODE Pdro
    PLUGIN_CODE PLGD
    FORMATS VST3
    PRODUCT_NAME "${PLUGIN_NAME}"
)

# Ajout des sources
target_sources(${PLUGIN_NAME} PRIVATE
    PluginProcessor.cpp
    PluginEditor.cpp
)

# Dépendances JUCE
target_link_libraries(${PLUGIN_NAME} PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_dsp
)
