#!/bin/sh
# tst.sh

./bld.sh; if [ $? -ne 0 ]; then exit 1; fi

LD_PRELOAD=./libpreloadprintf.so ./hello
