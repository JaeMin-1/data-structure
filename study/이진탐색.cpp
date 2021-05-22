#include <iostream>
using namespace std;
int binsearch(int list[], int num, int left, int right);
int Rbinsearch(int list[], int num, int left, int right);
char compare(int x, int y);
int middle;

int main() {
	int list[] = { 10,20,30,40,50,60,70,80,90,100 };
	int left = 0; int right = 9;
	int num; int method;
	int search;
	char answer = 'Y';

	while (answer == 'Y') {
		cout << "Enter method : 1. Bin-search  2. Recursive search : ";
		cin >> method;
		cout << "Enter an integer to search : ";
		cin >> num;

		if (method == 1) search = binsearch(list, num, left, right);
		else search = Rbinsearch(list, num, left, right);

		if (search == -1) cout << "Not in the list" << endl << endl;
		else {
			search = search + 1;
			cout << "Found at position : " << search << endl << endl;
		}

		cout << "Again (Y,N)? : "; cin >> answer;
		cout << endl;
		if (answer == 'N') break;
	}
	
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

		switch (compare(list[middle], num)) {
		case 1: return Rbinsearch(list, num, left, middle - 1);
		case 0: return middle;
		case -1: return Rbinsearch(list, num, middle + 1, right);
		}

		if (num < list[middle]) return Rbinsearch(list, num, left, middle - 1);
		else if (num == list[middle]) return middle;
		else return Rbinsearch(list, num, middle + 1, right);
	} return -1;
}

char compare(int x, int y) {
	if (x > y) return 1;
	else if (x < y) return -1;
	else return 0;
}