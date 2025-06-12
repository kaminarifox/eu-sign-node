#!/bin/sh

docker build -t eu-sign-node:latest -f Dockerfile .
docker run --name eu-sign-node-test -it --rm -v $(pwd):/usr/src/app eu-sign-node:latest