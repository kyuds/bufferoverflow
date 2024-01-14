FROM ubuntu:noble-20231221 AS build

# add build dependencies
RUN apt-get update
RUN apt-get -y --no-install-recommends install \
    build-essential clang

# copy over files
WORKDIR /proj
COPY ./bfo.c .
COPY ./bfo.h .

# setup and compile with appropriate settings
RUN sysctl -w kernel.randomize_va_space=0
RUN gcc -fno-stack-protector bfo.c -w -o bfo
RUN chmod +x bfo
