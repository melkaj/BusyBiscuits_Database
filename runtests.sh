#!/bin/sh

cd test
g++ temp.cpp ../lib/catch2/catch_amalgamated.cpp -o test
./test
