////////////////////////////////////////////////////////////////////////
// Lab0: Find Min and Max numbers
// Name: ±Ë¿ÁπŒ
// ID: 20181592
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int findMin(int data[], int n);
int findMax(int data[], int n);
int pos = 1;

int main() {
	int minnum, maxnum, size = 10;
	//int data[10];
	int data[] = {3, 15, 17, 34, 46, 76, 86, 92, 96, 32};

	//ifstream infile;
	//infile.open("input.txt", ios::in);
	//if (infile.fail()) { cout << "can't open the input file" << endl; exit(1); }

	//for (int i = 0; i < size; i++) infile >> data[i];
	for (int i = 0; i < size; i++) {
		cout << "data[" << i << "]: " << data[i] << endl;
	}

	minnum = findMin(data, size);
	cout << "Min number is " << minnum << " at position " << pos << endl;

	pos = 1;
	maxnum = findMax(data, size);
	cout << "Max number is " << maxnum << " at position " << pos << endl;
	//infile.close();
	return 0;
}

int findMin(int data[], int n) {
	int min = data[0];

	for (int i = 1; i < n; i++)
		if (data[i] < min) { min = data[i]; pos = i + 1; }
	return min;
}

int findMax(int data[], int n) {
	int max = data[0];

	for (int i = 1; i < n; i++)
		if (data[i] > max) { max = data[i]; pos = i + 1; }
	return max;
}