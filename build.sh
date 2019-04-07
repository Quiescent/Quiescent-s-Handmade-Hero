#!/bin/bash

set -e

BUILD_DIR=bin

mkdir -p $BUILD_DIR

SDL_C_FLAGS=$(sdl2-config --cflags)

LINK=-l"SDL2"

EXTRAS=

if [ "$1" == "debug" ]; then
    EXTRAS="-g $EXTRAS"
fi

pushd $BUILD_DIR
echo g++ ../src/handmade.cpp $EXTRAS $SDL_C_FLAGS $LINK -o ../$BUILD_DIR/handmade
g++ ../src/handmade.cpp $EXTRAS $SDL_C_FLAGS $LINK -o ../$BUILD_DIR/handmade
popd
