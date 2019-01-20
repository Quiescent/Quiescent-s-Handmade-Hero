#!/bin/bash

set -e

BUILD_DIR=bin

mkdir -p $BUILD_DIR

INCLUDE=-I"/usr/include/SDL2/"

LINK=-l"SDL2-2.0"

pushd $BUILD_DIR
g++ ../src/handmade.cpp $INCLUDE $LINK -o ../$BUILD_DIR/handmade
popd
