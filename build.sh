#!/bin/bash

set -e

if [ -z "$CXX" ]; then
  if which g++ >/dev/null ; then
    CXX=g++
  elif which clang++ >/dev/null ; then
    CXX=clang++
  fi
fi

echo "CXX=$CXX"

mkdir -p bin
$CXX \
  -std=c++20 \
  -O2 \
  fs_bench.cpp \
  -o ./bin/fs_bench

echo "Built ./bin/fs_bench"
