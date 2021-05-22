#include <iostream>
using namespace std;

int Rfactorial(int n);
int factorial(int n);

int main() {
	int n;
	cin >> n;

	int f = Rfactorial(n);
	int ff = factorial(n);
	cout << f << endl << ff;

	return 0;
}

int Rfactorial(int n) {
	if (n == 0) return 1;
	else return n * Rfactorial(n - 1);
}

int factorial(int n) {
	int fact = 1;

	for (int i = 1; i <= n; i++) {
		fact = fact * i;
	} return fact;
}