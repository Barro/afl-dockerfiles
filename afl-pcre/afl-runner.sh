#!/bin/sh

set -eux

ROLE=$1
ID=$2

APP_NAME=pcre-compile
APP_PATH=/tmp/"$APP_NAME"
FUZZROOT=/fuzzdata/pcre-fuzz
INDIR="$FUZZROOT"/input
OUTDIR="$FUZZROOT"/output

mkdir -p "$OUTDIR"

AFL_SKIP_BIN_CHECK=true \
    AFL_SKIP_CPUFREQ=true \
    afl-fuzz -i "$INDIR" -o "$OUTDIR"  "$ROLE" "$APP_NAME"-"$ID" "$APP_PATH"
