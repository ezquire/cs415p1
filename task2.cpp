/* 
 * Assignment: Empirical Analysis of Algorithms
 * Group: Tyler Gearing, Mei Williams
 * File: task2.cpp
 */

#include <iostream>
#include <fstream>

using namespace std;

// Function prototypes
unsigned int gcd(unsigned int, unsigned int, double&);
double mdAvg(double);
unsigned long fib(unsigned int);

int main() {

	ofstream euclid;
	double md = 0;

	euclid.open("euclid2.txt", ios::out);
	
	for(unsigned int i = 5; i < 100; i += 5) {
		euclid << i << " " << mdAvg(i) << endl;
	}

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
