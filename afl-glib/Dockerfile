FROM barro/afl-base
MAINTAINER Jussi Judin <jjudin+docker@iki.fi>

#ENV GLIB_VERSION 2.45.1
ENV GLIB_VERSION master

RUN apt-get update && apt-get install -y \
    pkg-config \
    autoconf \
    automake \
    libtool \
    zlib1g-dev \
    libffi-dev \
    gettext

RUN git clone git://git.gnome.org/glib \
    && cd glib \
    && git checkout "$GLIB_VERSION" \
    && ./autogen.sh \
    && /tmp/glib/configure --prefix=/usr --disable-shared \
    && make -j \
    && make install

COPY build.sh \
     afl-runner.sh \
     glib-base64.c \
     glib-bookmark.c \
     glib-date.c \
     glib-glob.c \
     glib-hostname.c \
     glib-i18n.c \
     glib-kv-parser.c \
     glib-pcre.c \
     glib-unicode.c \
     glib-unicode-locales.c \
     glib-uri.c \
     result-process.sh \
     /tmp/
RUN ./build.sh \
    base64 \
    bookmark \
    date \
    glob \
    hostname \
    i18n \
    kv-parser \
    pcre \
    unicode \
    unicode-locales \
    uri
