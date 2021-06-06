////////////////////////////////////////////////////////////////////////
// Lab1-2 : word cout
// Name: ±Ë¿ÁπŒ
// ID: 20181592
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
//#include <string>
using namespace std;
void countWord(char buffer[], int& wc);

void main() {
	ifstream infile;
	char buffer[80]; int wc; int total = 0;

	infile.open("lab1-2.txt", ios::in);
	if (infile.fail()) {
		cout << "can't open the input file" << endl; exit(1);
	}
	while (infile.getline(buffer, 80)) {
		cout << buffer << endl;
		countWord(buffer, wc);
		cout << "The number of words : " << wc << endl;
		total = total + wc;
	}
	cout << endl << endl << "The total number of words: " << total << endl << endl;
}

void countWord(char buffer[], int& wc) {
	const int IN = 1;
	const int OUT = 0;

	int i = 0; int state = OUT;
	wc = 0;

	while (buffer[i] != '\0') {
		if (isalpha(buffer[i])) {
			if (state == OUT) {
				++wc;
				state = IN;
			}
		}
		else if (buffer[i] == ' ') state = OUT;

		i++;
	}
}