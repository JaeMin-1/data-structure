#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int row = 6;
    const int col = 6;
    int A[row][col];
    ifstream infile;

    infile.open("Lab4.txt", ios::in);
    if (infile.fail()) { cout << "can't open the input file" << endl; exit(1); }
   
    cout << "1) Original Matrix : A" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            infile >> A[i][j];
            cout << A[i][j] << " ";
        }
        cout << endl;
    } cout << endl << endl;

    int s = 0;
    int B[100][3];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (A[i][j] != 0) {
                B[s][0] = i;
                B[s][1] = j;
                B[s][2] = A[i][j];
                s++;
            }
        }
    }
    cout << "2) (matrix B) - row major" << endl;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < 3; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}