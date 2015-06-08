FROM ubuntu:14.10
MAINTAINER Jussi Judin <jjudin+docker@iki.fi>

ENV AFL_VERSION 1.73b

RUN apt-get update
RUN apt-get install -y \
    libc6-dev \
    libc++-dev \
    gcc \
    g++ \
    make \
    wget \
    gdb
RUN cd /tmp && wget http://lcamtuf.coredump.cx/afl/releases/afl-"$AFL_VERSION".tgz
RUN cd /tmp \
    && tar xf afl-"$AFL_VERSION".tgz \
    && cd afl-"$AFL_VERSION" \
    && make -j all install PREFIX=/usr
RUN rm -rf /tmp/afl-"$AFL_VERSION"*
