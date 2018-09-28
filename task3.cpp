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
