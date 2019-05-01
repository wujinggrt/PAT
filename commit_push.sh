#!/bin/bash
read -p "Commit message:"
git add .
git commit -m "${REPLY}"
git gc
git push origin master