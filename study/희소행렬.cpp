#include <iostream>
using namespace std;
const int MAX_ROWS = 100; //열의 최대값
const int MAX_COLS = 100; //행의 최대값


int main() {
    int a[100][3];
    int b[100][3];

    int A[6][6] = 
    {
        { 15, 0, 0, 22, 0, -15 },
        { 0, 11, 3, 0, 0, 0 },
        { 0, 0, 0, -6, 0, 0 },
        { 0, 0, 0, 0, 0, 0 },
        { 91, 0, 0, 0, 0, 0 },
        { 0, 0, 28, 0, 0, 0 }
    };

    int s = 1;
    a[0][0] = 6;
    a[0][1] = 6;
    a[0][2] = 8;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (A[i][j] != 0) {
                a[s][0] = i;
                a[s][1] = j;
                a[s][2] = A[i][j];
                s++;
            }
        }
    }
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 6; i++) {
            if (A[i][j] != 0) {
                a[s][0] = j;
                a[s][1] = i;
                a[s][2] = A[i][j];
                s++;
            }
        }
    }

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}