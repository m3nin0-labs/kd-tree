#!/bin/bash

set -e

#
# Prepare build directory
#
mkdir -p build
cd build

#
# Compile
#
cmake ../src
make

#
# Run
#
./kdtree.bin
