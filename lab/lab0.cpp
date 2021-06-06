#include <iostream> // 표준 입출력 헤더파일 (cin/cout)
#include <fstream> // read-write file class
#include <string> //string library
using namespace std;
int main() {
	char buffer[80]; // read one line
	ifstream inFile("lab0.txt"); //데이터 입력후 소스위치에 저장
	ofstream outFile("output.txt"); // output file
	// input Stream이 열렸는지 확인
	if (!inFile.is_open()) {
		cerr << "error: input.txt를 열수없슴. " << endl; return 1;
	}
	//input Stream이 EOF에 도달할 때 까지
	while (inFile.getline(buffer, 80)) {
		cout << buffer << endl;
	} //데이터 파일을 화면에 출력
// output Stream이 열렸는지 확인
	if (!outFile.is_open()) {
		cerr << "error: output.txt열수 없음" << endl; return 1; }
	if (outFile.is_open()) {
		outFile << "this is output file ";
			} // 파일에 출력
//파일을 열었을 경우 반드시 닫아 주어야 저장된다.
		inFile.close();
		outFile.close();
		return 0;
} //end of main