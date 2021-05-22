#include <iostream>
#define swap(a,b) {int t; t=a; a=b; b=t;}
using namespace std;
void selsort(int list[], int n);

int main() {
	int list[] = { 9,6,7,3,5 };
	int n = size(list);

	selsort(list, n);
	cout << "Sorted array : ";
	for (int i = 0; i < n; i++) cout << " " << list[i] << " ";

	return 0;
}

void selsort(int list[], int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min]) min = j;
		swap(list[i], list[min]);
	}
}

