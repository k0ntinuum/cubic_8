#!/bin/bash
clang shred.c -O1 -L /opt/homebrew/lib/ -I /opt/homebrew/include/ -lraylib -std=c2x -o s && ./s