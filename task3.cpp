#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

// Function prototypes
vector<bool> sieve (unsigned long);

int main () {

	int n = 4;

	vector<bool> p = sieve(100);

	for(int i = 0; i < p.size(); ++i)
		if(p[i])
			cout << i  << endl;
	
	return 0;

}

vector<bool> sieve (unsigned long n) {
	vector<bool> A(n);
	for(int i = 0; i < n; ++i)
		A[i] = 1;
	
	for(unsigned long i = 2; i*i <= n; ++i) {
		if(A[i]) {
			for(unsigned long j = i*2; j <= n; j += i) {
				A[j] = 0;
			}
		}
	}
	return A;
}
