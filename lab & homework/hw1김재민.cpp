////////////////////////////////////////////////////////////////////////
// Name : 김재민
// Student ID : 20181592
// Program ID : hw1
// Description : 외부의 파일을 입력받아 자유자재로 왼쪽 정렬, 오른쪽 정렬, 가운데 정렬을 할 수 있도록 하기 위한 프로그램
//
// Algorithm :  어떤 정렬을 실행할지 혹은, 프로그램을 종료할지 해당하는 숫자를 입력한다.
//              1을 입력했다면 외부의 파일(hw1.txt)을 받아와서 왼쪽 정렬을 해서 출력하고
//              2을 입력했다면 외부의 파일(hw1.txt)을 받아와서 오른쪽 정렬을 해서 출력하며,
//              3을 입력했다면 외부의 파일(hw1.txt)을 받아와서 가운데 정렬을 해서 출력한다.
//              마지막으로 4를 입력한다면 프로그램을 종료한다.
//
// Variables :  Left_justification() - 왼쪽 정렬
//              Right_justification() - 오른쪽 정렬
//              Centered_justification() - 가운데 정렬
//              length_check(int count) - 빈 공간의 길이 확인
//              char buffer[80] - 데이터를 읽기 위한 길이 80의 char형 배열 선언
//              char stringbuffer[80] - 데이터를 출력하기 위한 길이 80의 char형 배열 선언
//              int i = 0 - 인덱스값 i 선언 및 초기화
//              ifstream infile - 외부의 파일 받아오기
//              int num = 0 - 처음 입력할 num 을 선언 및 0으로 초기화
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
using namespace std;

void Left_justification();
void Right_justification();
void Centered_justification();
void length_check(int count);

char buffer[80];        // 데이터를 읽기 위한 길이 80의 char형 배열 선언
char stringbuffer[80];  // 데이터를 출력하기 위한 길이 80의 char형 배열 선언
int i = 0;              // 인덱스값 i 선언 및 초기화

int main() {
	int num = 0;
	
	while (num != 4) {                                               // 4. Terminate 가 아닐시 계속 실행
		cout << "**************************************" << endl;    
		cout << "1. Left     Justification" << endl;                 // 왼쪽 정렬
		cout << "2. Right    Justification" << endl;                 // 오른쪽 정렬
		cout << "3. Centered Justification" << endl;                 // 가운데 정렬
		cout << "4. Terminate" << endl << endl;                      // 종료

		cout << "Enter your choice : "; cin >> num; cout << endl;    // 원하는 정렬 혹은 종료에 해당하는 숫자 입력

		for (int i = 0; i < 8; i++) {                                // 자릿수를 잘 보여주기 위한 숫자라인
			cout << "1234567890";
		} cout << endl << endl;

		if (num == 1) {
			Left_justification();
			cout << endl;
		}
		else if (num == 2) {
			Right_justification();
			cout << endl;
		}
		else if (num == 3) {
            Centered_justification();
			cout << endl;
		}
	}

	return 0;
}

void Left_justification() {                // 왼쪽 정렬
    ifstream infile;                       // 외부의 파일 받아오기
    infile.open("hw1.txt", ios::in);
    if (infile.fail()) {
        cout << "파일을 열수 없습니다" << endl;
        exit(1);
    }

    while (infile.getline(buffer, 80)) {   // 한 라인을 읽음
        while (buffer[i] != '\0') {        // 라인의 문자가 '\0'이 아닐 때까지, 즉 라인의 끝이 아닐 때까지
            stringbuffer[i] = buffer[i];   // 출력할 배열 stringbuffer에 데이터 삽입
            i++;                           // 인덱스 값 증가.
        }
        stringbuffer[i] = '\0';            // end of line 추가
        cout << stringbuffer << endl;      // stringbuffer 출력
        stringbuffer[0] = '\0';            // 다음 라인을 새로 받기 위해 stringbuffer를 다시 '\0'으로 초기화
                                           // (* hw1.txt 같은 경우는 필요가 없지만, 앞 라인보다 뒷 라인이 짧다면 꼭 필요함)
        i = 0;                             // 인덱스 값 i 역시 0으로 초기화
    }
    cout << endl;

    infile.close();
}

void Right_justification() {               // 오른쪽 정렬         
    ifstream infile;                       // 외부의 파일 받아오기
    infile.open("hw1.txt", ios::in);
    if (infile.fail()) {
        cout << "파일을 열수 없습니다" << endl;
        exit(1);
    }

    while (infile.getline(buffer, 80)) {   // 한 라인을 읽음
        while (buffer[i] != '\0') {        // 라인의 문자가 '\0'이 아닐 때까지, 즉 라인의 끝이 아닐 때까지
            i++;                           // 인덱스 값 증가
        }

        length_check(i);                   // 빈 공간의 길이 체크
        i = 0;                             // 인덱스 값을 다시 0으로 초기화

        while (buffer[i] != '\0') {
            stringbuffer[i] = buffer[i];   // 출력할 배열 stringbuffer에 데이터 삽입.
            i++;                           // 인덱스 값 증가
        }

        stringbuffer[i] = '\0';            // end of line 추가
        cout << stringbuffer << endl;      // stringbuffer 출력
        stringbuffer[0] = '\0';            // 다음 라인을 새로 받기 위해 stringbuffer를 다시 '\0'으로 초기화
        i = 0;                             // 인덱스 값 i 역시 0으로 초기화
        
    }
    cout << endl;

    infile.close();
}

void Centered_justification() {            // 가운데 정렬
    int blank_space = 0;                   // 빈칸 계산해서 넣을 변수 blank_space 선언

    ifstream infile;                       // 외부의 파일 받아오기
    infile.open("hw1.txt", ios::in);
    if (infile.fail()) {
        cout << "파일을 열수 없습니다" << endl;
        exit(1);
    }

    while (infile.getline(buffer, 80)) {   // 한 라인을 읽음
        while (buffer[i] != '\0') {        // 라인의 문자가 '\0'이 아닐 때까지, 즉 라인의 끝이 아닐 때까지
            i++;                           // 인덱스 값 증가
        }

        blank_space = (79 - i) / 2;        // 가운데 정렬을 위해 2로 나눈 값을 저장
        i = 0;                             // 인덱스 값을 다시 0으로 초기화

        for (int j = 0; j <= blank_space; j++)
            cout << ' ';                   // 빈칸 수만큼 공백 출력

        while (buffer[i] != '\0') {        // 라인의 문자가 '\0'이 아닐 때까지, 즉 라인의 끝이 아닐 때까지
            stringbuffer[i] = buffer[i];   // 출력할 배열 stringbuffer에 데이터 삽입
            i++;                           // 인덱스 값 증가
        }

        stringbuffer[i] = '\0';            // end of line 추가
        cout << stringbuffer << endl;      // stringbuffer 출력
        stringbuffer[0] = '\0';            // 다음 라인을 새로 받기 위해 stringbuffer를 다시 '\0'으로 초기화
        i = 0;                             // 인덱스 값 i 역시 0으로 초기화
    }

    infile.close();
}

void length_check(int count) {             // 빈 공간의 길이 확인
    for (int i = 0; i <= 79 - count; i++)   cout << ' ';    // 최대길이 79에서 데이터 길이를 뺀 만큼 공백 출력.
}                             