#!/bin/bash

# Set compiler and flags
CXX=g++ 
CXXFLAGS="-std=c++17 -Wall" 
INCLUDE_DIR="include"
SOURCE_DIR="source"
OUTPUT_DIR="build"
OUTPUT="build/main"

# Make build directory if none exists
mkdir -p $OUTPUT_DIR

# Check if the include and source directories exist
echo "Checking directories..."
if [ ! -d "$INCLUDE_DIR" ]; then
  echo "Error: Include directory '$INCLUDE_DIR' is missing!"
  exit 1
fi

if [ ! -d "$SOURCE_DIR" ]; then
  echo "Error: Source directory '$SOURCE_DIR' is missing!"
  exit 1
fi

# Compile the project
echo "Compiling project..."

# Compiling all .cpp files in the source folder
$CXX $CXXFLAGS -I $INCLUDE_DIR $SOURCE_DIR/*.cpp -o $OUTPUT

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo "Build succeeded. Executable created: ./$OUTPUT"
    exit 0
else
    echo "Build failed."
    exit 1
fi

