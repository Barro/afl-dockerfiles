#!/bin/bash

target_dir="$1"
shift

for I in "$@"; do
    tail -c +1 "$I" > "$target_dir"/"$(basename "$I")"
done
