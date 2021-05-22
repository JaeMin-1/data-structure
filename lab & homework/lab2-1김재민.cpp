////////////////////////////////////////////////////////////////////////
// Lab2-1 : Simple Recursion Test 
// Name : ±èÀç¹Î
// ID : 20181592
/////////////////////////////////////////////////////////////////////////

#include <iostream>
//#include <string>
int add(int i, int j);
int diffs(int i, int j);
int sum(int num);
void Reverse(char S[], int size);
using namespace std;

int main() {
	int num1, num2;
	int n;
	char s[80];

	cout << "Enter number1 : "; cin >> num1;
	cout << "Enter number2 : "; cin >> num2;
	int sum1 = add(num1, num2);
	cout << "Sum is : " << sum1 << endl << endl;

	cout << "Enter number1 : "; cin >> num1;
	cout << "Enter number2 : "; cin >> num2;
	int Diff = diffs(num1, num2);
	cout << "Difference is : " << Diff << endl << endl;

	cout << "Enter any positive integer : "; cin >> n;
	int sum2 = sum(n);
	cout << "Sum of numbers : " << sum2 << endl << endl;

	cout << "Enter String : "; cin >> s;
	int size = strlen(s);
	cout << "Reverse of the string is : "; 
	Reverse(s, size);

	return 0;
}

int add(int i, int j) {
	if (i == 0) return j;
	else return add(--i, ++j);
}

int diffs(int i, int j) {
	if (i == 0) return j;
	else if (j == 0) return i;
	else return diffs(--i, --j);
}

int sum(int num) {
	if (num != 0) return num + sum(num - 1);
	else return num;
}

void Reverse(char S[], int size) {
	if (size == 0) return;
	else {
		cout << S[size - 1];
		Reverse(S, size - 1);
	}
}