#!/bin/sh

echo -n "Launching bot...\n\n"

cd /app
mkdir build
cmake -S . -B ./build
cd ./build
cmake --build .
./laurent "../.ohptnlaurent"
