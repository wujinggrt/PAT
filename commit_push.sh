#!/bin/bash

read -p "Enter commit message:"
git add .
git commit -am "${REPLY}"
git gc
git push origin master
