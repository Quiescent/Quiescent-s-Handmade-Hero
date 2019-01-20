#!/bin/bash

set -e

BUILD_DIR=bin

mkdir -p $BUILD_DIR

INCLUDE=-I"/usr/include/SDL2/"

LINK=-l"SDL2-2.0"

EXTRAS=

if [ "$1" == "debug" ]; then
    EXTRAS="-g $EXTRAS"
fi

pushd $BUILD_DIR
g++ ../src/handmade.cpp $EXTRAS $INCLUDE $LINK -o ../$BUILD_DIR/handmade
popd
