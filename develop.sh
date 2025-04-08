#!/bin/bash

docker build -t ak_doorbell_dev .

docker run --rm -it \
  -v `pwd`:/app \
  -w /app \
  ak_doorbell_dev
