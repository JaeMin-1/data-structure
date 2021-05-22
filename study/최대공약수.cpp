#include <iostream>
using namespace std;

int gcd(int a, int b);
int rgcd1(int a, int b);
int rgcd2(int a, int b);

int main() {
	int a; int b;
	cin >> a >> b;

	int g = gcd(a, b);
	int rg1 = rgcd1(a, b);
	int rg2 = rgcd2(a, b);
	cout << g << endl << rg1 << endl << rg2;

	return 0;
}

int gcd(int a, int b) {
	int d = 0; int r;
	if (a < b) { d = a; a = b; b = d; }

	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	} return a;
}

int rgcd1(int a, int b) {
	if ((a % b) == 0) return b;
	else return rgcd1(b, a % b);
}

int rgcd2(int a, int b) {
	if (a == b) return a;
	else if (a > b) return rgcd2(a - b, b);
	else return rgcd2(a, b - a);
}