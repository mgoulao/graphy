#!/bin/bash

BUILD_JS="-js"
BUILD_CPP="-cpp"

show_usage() {
	echo "Usage:"
	echo $0 "["$BUILD_CPP " or " $BUILD_JS"]"
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
else
	show_usage
fi

