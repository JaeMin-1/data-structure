#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	char answer = 'Y';

	for (int i = 2; i < num; i++) {
		if (num % i == 0) answer = 'N';
	}
	cout << answer;

	return 0;
}