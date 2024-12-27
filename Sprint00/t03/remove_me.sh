#!/bin/bash

for var in "$@"; do
    if [ -d "$var" ] && [ "$(ls -A "$var")" ]; then
        echo "rm: $var: Directory not empty"
    else
        rm -r "$var"
    fi
done
