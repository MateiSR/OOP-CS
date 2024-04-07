#!/bin/bash

clang++ --debug -Wall *.cpp -o a.out
if [ $? -ne 0 ]; then echo "error while compiling" >&2; exit 1
else echo "running compiled code"; (./a.out); fi
