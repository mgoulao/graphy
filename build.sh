#!/bin/bash

NAME=graphy_module
DESTINATION_DIR="../dist/"

JS_TARGET=$DESTINATION_DIR$NAME".js"
CPP_TARGET=$DESTINATION_DIR$NAME

JS_CC="em++"
CPP_CC="g++"

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
	make CC=$CPP_CC TARGET=$CPP_TARGET EMFLAGS=""
elif [[ $BUILD_JS == $1 ]];
then
	echo $JS_TARGET
	cd src
	make CC=$JS_CC TARGET=$JS_TARGET CFLAGS="" LDFLAGS="--bind"
else
	show_usage
fi

