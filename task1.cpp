/* 
 * Assignment: Empirical Analysis of Algorithms
 * Group: Tyler Gearing, Mei Williams
 * File: task1.cpp
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
		else {
			d += 2;
			--t;
		}
	}
}
