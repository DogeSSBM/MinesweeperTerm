#!/bin/sh
printf "\033c"
flags="-Wall -Wextra -pedantic -Wno-missing-braces"
gcc main.c $flags -o main.out
