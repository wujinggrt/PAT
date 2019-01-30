#!/bin/bash

clang++ ./cp.cpp
cat i.dat | ./a.out
echo 'Next test'
cat i2.dat | ./a.out
