#!/bin/bash

INSTALL_DIR = "C:\Repositories\Adon\output\lib"

echo "sourcing config file"

source config.cfg

echo "checking build type"

if [[ ! -n $BUILD_ALL_ABI ]] && [[ -z $BUILD_ALL_ABI ]]
then
	BUILD_ALL_ABI="true"
fi

echo "checking if directory exists, else build it"

if [ ! -d "$ANDRIOD_BUILD_DIR" ]
then
	mkdir -p $ANDRIOD_BUILD_DIR
	cd $ANDRIOD_BUILD_DIR
else
	cd $ANDRIOD_BUILD_DIR
fi

echo "executing build"

if [ ! -z $BUILD_ALL_ABI ]
then
for ABI in "x86" "x86_64" "arm64-v8a" "armeabi-v7a"
do
COMMAND_CMAKE_BUILD="eval $CMAKE_EXE_PATH -G Unix\ Makefiles -DCMAKE_TOOLCHAIN_FILE=$ANDROID_TOOLCHAIN_FILE ../../ -DCMAKE_MAKE_PROGRAM=$MAKE_EXE_PATH -DCMAKE_BUILD_TYPE=$CMAKE_BUILD_TYPE -DANDROID_NATIVE_API_LEVEL=$ANDROID_API_LEVEL -DANDROID_NDK=$ANDROID_NDK_PATH -DANDROID_ABI=$ABI -DANDROID_STL=$ANDROID_STL -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR"
$COMMAND_CMAKE_BUILD || exit 1
eval $CMAKE_EXE_PATH --build . || exit 1
done
fi
