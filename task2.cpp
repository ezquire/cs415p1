/* 
 * Assignment: Empirical Analysis of Algorithms
 * Group: Tyler Gearing, Mei Williams
 * File: task2.cpp
 */

/*
  MIT License

  Copyright (c) 2018 Tyler Gearing

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in 
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>

using namespace std;

// Function prototypes
unsigned int gcd(unsigned int, unsigned int, double&);
double mdAvg(double);
unsigned long fib(unsigned int);

int main() {

	ofstream euclid;
	ofstream timeeuclid;
	double md = 0;

	euclid.open("euclid2.txt", ios::out);
	timeeuclid.open("timeeuclid.txt", ios::out);

    for(int i = 0; i < 20; ++i) {
        clock_t start = clock();
	
        for(unsigned int i = 5; i < 100; i += 5) {
		    euclid << i << " " << mdAvg(i) << endl;
	    }
        
        clock_t end = clock();
        timeeuclid << ((end - start) / (double) CLOCKS_PER_SEC) << endl;
	}
    timeeuclid.close();
    euclid.close();
	
	return 0;
}

unsigned int gcd(unsigned int m, unsigned int n, double& md) { 
    if (m == 0) 
        return n;
	else {
		++md;
		return gcd(n%m, m, md);
	}
}

double mdAvg(double n) {
	double md = 0;
	for(int i = 0; i < n; ++i) {
		gcd(fib(i+1), fib(i), md);
	}
	return (md/n);
}

// return the n'th Fibonacci number
unsigned long fib(unsigned int n) {
	unsigned long previous = 0;
    unsigned long current = 1;
	if (n == 0)
		return 0;
    for (unsigned int i = 1; i < n; ++i) {
        unsigned long next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}
