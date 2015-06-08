#!/bin/bash

set -eux

for type in "$@"; do
    afl-gcc -static -g -o glib-"$type" glib-"$type".c $(pkg-config --cflags --libs glib-2.0) -lpthread
    gcc -static -ggdb -o glib-"$type"-plain glib-"$type".c $(pkg-config --cflags --libs glib-2.0) -lpthread
done
