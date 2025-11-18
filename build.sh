#!/bin/bash

PLUGIN_NAME=$1

mkdir -p build
cd build

cmake .. -DPLUGIN_NAME="$PLUGIN_NAME"
cmake --build . --config Release

mkdir -p /output
zip -r "/output/${PLUGIN_NAME}.zip" .
