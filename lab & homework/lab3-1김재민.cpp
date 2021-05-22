////////////////////////////////////////////////////////////////////////
// Lab3-1 : Magic Square problem
// Name : �����
// ID : 20181592
/////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int square[100][100];

int main() {
	int key = 2;
	int n;
	int row; int col;

	cout << "enter number of square : ";
	cin >> n;
    cout << endl;

	int i = 0; int j = n / 2;
	square[i][j] = 1;


	while (key <= n * n) {
		if (i - 1 < 0) row = n - 1; else row = i - 1;
		if (j - 1 < 0) col = n - 1; else col = j - 1;

		if (square[row][col]) i = (i + 1) % n;
		else { i = row; j = col; }
		square[i][j] = key++;
	}
    cout << "magic square size is " << n << endl << endl;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cout << square[x][y] << "  ";
		}
        cout << endl << endl;
	}
	
	return 0;
}