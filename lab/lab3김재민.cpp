////////////////////////////////////////////////////////////////////////
// Lab3 : Binary Search
// Name : �����
// ID : 20181592
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#define swap(a,b) {int t; t=a; a=b; b=t;}

using namespace std;
int binsearch(int list[], int num, int left, int right);
int Rbinsearch(int list[], int num, int left, int right);
int Search(int list[], int num);
void SelectionSort(int list[], int n);
int middle;

int main() {
	int list[10]; int size = 10;
	int left = 0; int right = 9;
	int num; int method;
	int search;
	char answer = 'Y';

	ifstream infile;
	infile.open("Lab3.txt", ios::in);
	if (infile.fail()) { cout << "can't open the input file" << endl; exit(1); }
	for (int i = 0; i < 10; i++) infile >> list[i];

	cout << "Numbers in the Data File : " << endl << endl;
	cout << "before sort : ";
	for (int i = 0; i < size; i++) cout << " " << list[i] << " ";
	cout << endl << endl;
	SelectionSort(list, size);
	cout << "Sorted array : ";
	for (int i = 0; i < size; i++) cout << " " << list[i] << " ";
	cout << endl << endl;

	while (answer == 'Y') {
		cout << "Enter method : 1. Bin-search  2. Recursive search  3. Sequential search : ";
		cin >> method;
		cout << "Enter an integer to search : ";
		cin >> num;

		if (method == 1) search = binsearch(list, num, left, right);
		else if (method == 2) search = Rbinsearch(list, num, left, right);
		else search = Search(list, num);

		if (search == -1) cout << "Not in the list" << endl << endl;
		else {
			search = search + 1;
			cout << "Found at position : " << search << endl << endl;
		}

		cout << "Again (Y,N)? : "; cin >> answer;
		cout << endl;
		if (answer == 'N') break;
	}
	infile.close();
	return 0;
}

int binsearch(int list[], int num, int left, int right) {
	while (left <= right) {
		middle = (left + right) / 2;
		if (num < list[middle]) right = middle - 1;
		else if (num == list[middle]) return middle;
		else left = middle + 1;
	} return -1;
}

int Rbinsearch(int list[], int num, int left, int right) {
	if (left <= right) {
		middle = (left + right) / 2;
		if (num < list[middle]) return Rbinsearch(list, num, left, middle - 1);
		else if (num == list[middle]) return middle;
		else return Rbinsearch(list, num, middle + 1, right);
	} return -1;
}

int Search(int list[], int num) {
	for (int i = 0; i < num; i++) {
		if (num == list[i]) return i;
	} return -1;
}

void SelectionSort(int list[], int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min]) min = j;
		swap(list[i], list[min]);
	}
}