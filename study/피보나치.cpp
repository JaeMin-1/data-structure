#include <iostream>
using namespace std;

int RFibonacci(int n);
int Fibonacci(int n);

int main() {
	int n;
	cin >> n;
	
	int RF = RFibonacci(n);
	int F = Fibonacci(n);
	cout << RF << endl << F;


	return 0;
}

int RFibonacci(int n) {
	if ((n == 0) || (n == 1)) return n;
	else return (RFibonacci(n - 1) + RFibonacci(n - 2));
}

int Fibonacci(int n) {
	int fn = 0; int f1 = 1; int f0 = 0;

	if (n <= 1) return n;
	else {
		for (int i = 2; i <= n; i++) {
			fn = (f1 + f0);
			f0 = f1;
			f1 = fn;
		} return fn;
	} 
}