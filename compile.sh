#!/bin/sh
printf "\033c"
flags="-Wall -Wextra -pedantic -Wno-missing-braces"
cc main.c $flags -o main.out
