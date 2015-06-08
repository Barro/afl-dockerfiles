#!/bin/bash

target_dir="$1"

for filetype in gd tga wbmp xbm; do
    for I in *."$filetype"; do
        cat "$filetype" "$I" > "$target_dir"/"$I"
    done
done
