FROM barro/afl-base
MAINTAINER Jussi Judin <jjudin+docker@iki.fi>

ENV IMLIB2_VERSION 1.4.7

RUN apt-get update && apt-get install -y pkg-config libfreetype6-dev libx11-dev

ENV CC afl-gcc
ENV CXX afl-g++

WORKDIR /tmp
RUN wget http://sourceforge.net/projects/enlightenment/files/imlib2-src/"$IMLIB2_VERSION"/imlib2-"$IMLIB2_VERSION".tar.bz2/download -O imlib2-"$IMLIB2_VERSION".tar.bz2 \
    && tar xf imlib2-"$IMLIB2_VERSION".tar.bz2 \
    && cd imlib2-"$IMLIB2_VERSION" \
    && mkdir build \
    && cd build \
    && ../configure --without-x --prefix=/usr \
    && make -j \
    && make install

COPY imlib2-runner.c /tmp/
RUN afl-gcc -o imlib2-runner imlib2-runner.c -lImlib2 -lm -ldl
