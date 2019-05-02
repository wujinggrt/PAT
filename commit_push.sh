#!/bin/bash

read -p "Enter commit message:"
git add .
git commit -m "${REPLY}"
git gc
git push origin master
