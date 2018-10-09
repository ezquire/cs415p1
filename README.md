# Empirical Analysis of Algorithms
[![Build Status](https://travis-ci.com/ezquire/empirical-analysis.svg?branch=master)](https://travis-ci.com/ezquire/empirical-analysis)

A simple analysis of several algorithms that calculate the greatest common demonitator of two integers.

## Group

Tyler Gearing, Mei Williams


Usage
-----

To build the various task executables run
```
make
```

Then you can run all the programs from the current directory by typing
```
./task[x]
```

Each task will generate one or more text files that can be used with the provided gnuplot scripts to make a scatterplot
```
euclid.txt
consec.txt
euclid2.txt
```

To generate the scatterplot graphs run
```
gnuplot scatterx.gnuplot
```

To clear the output files and executables use
```
make clean
```
