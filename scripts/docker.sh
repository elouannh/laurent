#!/bin/bash

docker container remove laurent-$1-omg
docker build -t laurent-$1 -f envs/$1/Dockerfile . && \
docker run --rm --cpuset-cpus="0-7" --name laurent-$1-omg laurent-$1
