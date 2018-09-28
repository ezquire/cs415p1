/* 
 * Assignment: Empirical Analysis of Algorithms
 * Group: Tyler Gearing, Mei Williams
 * File: task1.cpp
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

using namespace std;

// Function prototypes
int gcd(int, int, double&);
int consec(int, int, double&);
double dAvg(double);
double mdAvg(double);

int main() {

	ofstream euclid;
	ofstream consec;
	euclid.open("euclid.txt", ios::out);
	consec.open("consec.txt", ios::out);

	for(double i = 5; i < 100; i += 5) {
		euclid << i << " " << mdAvg(i) << endl; // Euclid's
		consec << i << " " << dAvg(i) << endl;  // Consecutive 
	}

	euclid.close();
	consec.close();
	
	return 0;
}

int gcd(int m, int n, double& md) { 
    if (m == 0) 
        return n;
	else {
		++md;
		return gcd(n%m, m, md);
	}
}

double mdAvg(double n) {
	double md = 0;
	for(int i = 1; i <= n; ++i) {
		gcd(i, n, md);
	}
	return (md/n);
}

double dAvg(double n) {
	double d = 0;
	for(int i = 1; i <= n; ++i) {
		consec(n, i, d);
	}
	return (d/n);
}

int consec(int m, int n, double& d) {
	int t = min(m, n);
	while(t != 0) {
		if((m%t == 0) && (n%t == 0))
			return t;
		else if(((m%t == 0) && !(n%t == 0)) || (!(m%t == 0) && (n%t == 0))) {
			++d;
			--t;
		}
		else {
			d += 2;
			--t;
		}
	}
}
