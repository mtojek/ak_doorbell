#!/bin/bash

docker build -t ak_doorbell_dev .

docker run --rm -it \
  --cap-add=SYS_PTRACE --security-opt seccomp=unconfined \
  -v `pwd`:/app \
  -w /app \
  ak_doorbell_dev
