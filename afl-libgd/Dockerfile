FROM barro/afl-base
MAINTAINER Jussi Judin <jjudin+docker@iki.fi>

#ENV LIBGD_VERSION gd-2.1.1
ENV LIBGD_VERSION master

RUN apt-get update && apt-get install -y cmake git zlib1g-dev

ENV CC afl-gcc
ENV CXX afl-g++

WORKDIR /tmp
RUN git clone https://github.com/libgd/libgd.git \
    && cd libgd \
    && git checkout "$LIBGD_VERSION" \
    && mkdir build \
    && cd build \
    && cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Debug \
    && make -j install

COPY libgd-runner.c /tmp/
COPY libgd-runner-gif.c /tmp/
COPY libgd-runner-tga.c /tmp/
RUN afl-gcc -o libgd-runner -static libgd-runner.c -lgd -lm
RUN afl-gcc -o libgd-runner-gif -static libgd-runner-gif.c -lgd -lm
RUN afl-gcc -o libgd-runner-tga -static libgd-runner-tga.c -lgd -lm
