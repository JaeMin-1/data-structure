#include <iostream>
#include <fstream>
using namespace std;

struct student
{
    string name;
    string idnum;
    double engpts;
    double mathpts;
    double average;
} student[5];

int main() {
    int i = 0; char buffer[80]; ifstream infile;

    infile.open("lab4-1.txt", ios::in);
    if (infile.fail()) { cout << "can't open the input file" << endl; exit(1); }

    while (true) {
        infile >> student[i].name >> student[i].idnum >> student[i].engpts >> student[i].mathpts;
        student[i].average = (student[i].engpts + student[i].mathpts) / 2.0;
        i++;
        if (infile.getline(buffer, 80))   continue;
        else break;
    }
    cout << endl << endl;

    i = 0;
    while (i <= 4) {
        cout << "Name : " << student[i].name << "    ";
        cout << "ID : " << student[i].idnum << "    ";
        cout << "English : " << student[i].engpts << "    ";
        cout << "Math : " << student[i].mathpts << "    ";
        cout << "Average : " << student[i].average << endl;
        i++;
    }
    infile.close();
    return 0;
}