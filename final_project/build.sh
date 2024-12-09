#!/bin/sh
current_directory="$(cd "$(dirname "$0")" && pwd)"
project_root_dir=$current_directory
cd ${project_root_dir}

# Installing External Libraries
echo -e "\nVerifying external libraries..."
mkdir -p ${project_root_dir}/third_party
cd ${project_root_dir}/third_party

if [ ! -d "SDL" ]; then
  echo "SDL not found, installing..."
  git clone https://github.com/libsdl-org/SDL
  cd ${project_root_dir}/third_party/SDL
  rm -rf build install
  mkdir -p build install
  cd build
  cmake -DCMAKE_INSTALL_PREFIX=${project_root_dir}/third_party/SDL/install -DCMAKE_BUILD_TYPE=Release ..
  cmake --build . -j 4 --config Release
  cmake --install .
fi
echo "SDL installed!"

# Compiling
echo -e "\nCompiling..."
cd ${project_root_dir}
rm -rf ${project_root_dir}/build
mkdir -p ${project_root_dir}/build
cd ${project_root_dir}/build
cmake ..
cmake --build . -j 4
cmake --install .
echo "Build complete!"
./build/chess