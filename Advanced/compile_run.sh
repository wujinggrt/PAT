#!/bin/bash

clang++ --std=c++11  ./s.cpp
echo "compiled!"
echo "testing:"
cat i.dat | ./a.out
# 如果存在两组数据或者三组
if [ -f ./i2.dat ];then
    echo "2nd testing:"
    cat i2.dat | ./a.out
    if [ -f ./i3.dat ];then
        echo "3rd testing:"
        cat i3.dat | ./a.out
    fi
fi
