#include <iostream> // ǥ�� ����� ������� (cin/cout)
#include <fstream> // read-write file class
#include <string> //string library
using namespace std;
int main() {
	char buffer[80]; // read one line
	ifstream inFile("lab0.txt"); //������ �Է��� �ҽ���ġ�� ����
	ofstream outFile("output.txt"); // output file
	// input Stream�� ���ȴ��� Ȯ��
	if (!inFile.is_open()) {
		cerr << "error: input.txt�� ��������. " << endl; return 1;
	}
	//input Stream�� EOF�� ������ �� ����
	while (inFile.getline(buffer, 80)) {
		cout << buffer << endl;
	} //������ ������ ȭ�鿡 ���
// output Stream�� ���ȴ��� Ȯ��
	if (!outFile.is_open()) {
		cerr << "error: output.txt���� ����" << endl; return 1; }
	if (outFile.is_open()) {
		outFile << "this is output file ";
			} // ���Ͽ� ���
//������ ������ ��� �ݵ�� �ݾ� �־�� ����ȴ�.
		inFile.close();
		outFile.close();
		return 0;
} //end of main