#include <iostream>
using namespace std;

/*
int main() {
	int a; int b; int c;
	cin >> a; cin >> b; cin >> c;
	int large = a;

	if (b > large) large = b;
	if (c > large) large = c;

	cout << large;

	return 0;
}
*/

int main() {
	int a; int b; int c;
	cin >> a; cin >> b; cin >> c;
	int little = a;

	if (b < little) little = b;
	if (c < little) little = c;

	cout << little;

	return 0;
}