#!/bin/bash

set -eux

FUNC_TYPE=$1
DATA_TYPE=${2:-crashes}

APP_NAME=glib-"$FUNC_TYPE"
APP_PATH=/tmp/"$APP_NAME"-plain
FUZZROOT=/fuzzdata/glib-fuzz
OUTDIR="$FUZZROOT"/output-"$FUNC_TYPE"

for filename in "$OUTDIR"/*/"$DATA_TYPE"/id:*; do
    echo "$filename"
    time timeout 30 "$APP_PATH" < "$filename" || :
done
