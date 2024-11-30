#!/bin/bash

echo ""
echo "Running cppcheck"
echo ""
echo ""

cppcheck --enable=all --suppress=missingIncludeSystem src/*.cpp

echo ""
echo ""
echo "Running cpplint"
echo ""
echo ""

cpplint src/*.cpp
