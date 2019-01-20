#!/bin/bash

set -e

BUILD_DIR=bin

mkdir -p $BUILD_DIR

INCLUDE="/usr/include/SDL2/"

pushd $BUILD_DIR
g++ ../src/handmade.cpp -I$INCLUDE -o ../$BUILD_DIR/handmade
popd
