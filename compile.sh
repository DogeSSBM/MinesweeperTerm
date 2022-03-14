#!/bin/sh
printf "\033c"
flags="-Wall -Wno-missing-braces"
gcc main.c $flags -o main.out
