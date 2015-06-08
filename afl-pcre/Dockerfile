FROM barro/afl-base
MAINTAINER Jussi Judin <jjudin+docker@iki.fi>

ENV PCRE_VERSION 8.37

RUN wget http://sourceforge.net/projects/pcre/files/pcre/"$PCRE_VERSION"/pcre-"$PCRE_VERSION".tar.gz/download -O pcre-"$PCRE_VERSION".tar.gz \
    && tar xf pcre-"$PCRE_VERSION".tar.gz \
    && mkdir pcre-"$PCRE_VERSION"-build \
    && cd pcre-"$PCRE_VERSION"-build \
    && ../pcre-"$PCRE_VERSION"/configure --enable-static --prefix=/usr \
    && make -j \
    && make install

COPY pcre-compile.c afl-runner.sh /tmp/
RUN afl-gcc -static -g -o pcre-compile pcre-compile.c -lpcre \
    && gcc -static -ggdb -o pcre-compile-plain pcre-compile.c -lpcre
