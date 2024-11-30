#!/bin/bash

clang++ -std=c++17 -L/opt/homebrew/lib -I/opt/homebrew/include -ldpp src/*.cpp -o laurent
./laurent
