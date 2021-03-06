#!/bin/bash

export CC=`pwd`/../build/bin/clang
export CXX=`pwd`/../build/bin/clang++
make clean
make
rm mem.S rop.S enclave.S
objdump -D Enclave/BufferOverflow/Mem.o > mem.S
objdump -D Enclave/ROP/rop.o > rop.S
objdump -D enclave.so > enclave.S
