#!/bin/bash

BUILD_JS="-js"
BUILD_JS_RELEASE="-release"
BUILD_CPP="-cpp"

show_usage() {
	echo "Usage:"
	echo $0 "["$BUILD_CPP " | " $BUILD_JS " | " $BUILD_JS_RELEASE "]"
}

if [[ $BUILD_CPP == $1 ]];
then
	echo $CPP_TARGET
	cd src
	make clean
	make
elif [[ $BUILD_JS == $1 ]];
then
	echo $JS_TARGET
	cd src
	make clean
	make wasm
elif [[ $BUILD_JS_RELEASE == $1 ]];
then
	echo $JS_TARGET
	cd src
	make clean
	make wasm RELEASE=1
else
	show_usage
fi

