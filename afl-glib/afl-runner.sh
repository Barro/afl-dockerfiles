#!/bin/sh

set -eux

TYPE=$1
ROLE=$2
ID=$3

APP_NAME=glib-"$TYPE"
APP_PATH=/tmp/"$APP_NAME"
FUZZROOT=/fuzzdata/glib-fuzz
INDIR="$FUZZROOT"/input/"$TYPE"/
OUTDIR="$FUZZROOT"/output-"$TYPE"/

mkdir -p "$OUTDIR"

AFL_SKIP_BIN_CHECK=true \
    AFL_SKIP_CPUFREQ=true \
    afl-fuzz -i "$INDIR" -o "$OUTDIR"  "$ROLE" "$APP_NAME"-"$ID" "$APP_PATH"
