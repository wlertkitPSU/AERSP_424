#!/bin/sh
current_directory="$(cd "$(dirname "$0")" && pwd)"
project_root_dir=$current_directory
cd ${project_root_dir}

# Compiling
echo -e "\nCompiling..."
cd ${project_root_dir}
rm -rf ${project_root_dir}/build
mkdir -p ${project_root_dir}/build
cd ${project_root_dir}/build
cmake -G Ninja ..
cmake --build . -j 4
cmake --install .
echo "Build complete!"

./chess.exe