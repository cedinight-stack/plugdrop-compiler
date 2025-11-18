#!/bin/bash

echo "=== PlugDrop Cloud Compiler ==="
echo "Plugin to compile: $1"

sh build.sh "$1"

echo "Compilation complete."
