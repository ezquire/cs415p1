/* 
 * Assignment: Empirical Analysis of Algorithms
 * Group: Tyler Gearing, Mei Williams
 * File: task3.cpp
 */

/*
  MIT License

  Copyright (c) 2018 Tyler Gearing, Mei Williams

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
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

// Function prototypes
vector<unsigned long> sieve (unsigned long);
unsigned long msp(unsigned long, unsigned long);

int main () {

	vector<unsigned long> p = sieve(100);
	
	return 0;
}

vector<unsigned long> sieve (unsigned long n) {

	vector<bool> A(n);
	vector<unsigned long> p(n);
	
	for(int i = 0; i < n; ++i)
		A[i] = 1;
	
	for(unsigned long i = 2; i*i <= n; ++i) {
		if(A[i]) {
			for(unsigned long j = i*2; j <= n; j += i) {
				A[j] = 0;
			}
		}
	}
	for(int i = 0; i < A.size(); ++i)
		if(A[i])
			p.push_back(i);
	return p;
}

unsigned long msp(unsigned long m, unsigned long n) {
   	vector<unsigned long> mprimes = sieve(m);
	vector<unsigned long> nprimes = sieve(n);
	
}
