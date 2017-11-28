#!/bin/bash

export CC=`pwd`/../llvm/build/bin/clang
export CXX=`pwd`/../llvm/build/bin/clang++
make clean
make
