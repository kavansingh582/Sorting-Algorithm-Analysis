#!/bin/zsh

g++ -o generator generator.cc

./generator 100 > randomNum100
./generator 1000 > randomNum1k 
./generator 10000 > randomNum10k 
./generator 50000 > randomNum50k
./generator 100000 > randomNum100k
./generator 200000 > randomNum200k
./generator 300000 > randomNum300k
./generator 400000 > randomNum400k
./generator 500000 > randomNum500k
./generator 600000 > randomNum600k
./generator 700000 > randomNum700k
./generator 800000 > randomNum800k
./generator 900000 > randomNum900k
./generator 999999 > randomNum999k
