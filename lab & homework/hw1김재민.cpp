////////////////////////////////////////////////////////////////////////
// Name : �����
// Student ID : 20181592
// Program ID : hw1
// Description : �ܺ��� ������ �Է¹޾� ��������� ���� ����, ������ ����, ��� ������ �� �� �ֵ��� �ϱ� ���� ���α׷�
//
// Algorithm :  � ������ �������� Ȥ��, ���α׷��� �������� �ش��ϴ� ���ڸ� �Է��Ѵ�.
//              1�� �Է��ߴٸ� �ܺ��� ����(hw1.txt)�� �޾ƿͼ� ���� ������ �ؼ� ����ϰ�
//              2�� �Է��ߴٸ� �ܺ��� ����(hw1.txt)�� �޾ƿͼ� ������ ������ �ؼ� ����ϸ�,
//              3�� �Է��ߴٸ� �ܺ��� ����(hw1.txt)�� �޾ƿͼ� ��� ������ �ؼ� ����Ѵ�.
//              ���������� 4�� �Է��Ѵٸ� ���α׷��� �����Ѵ�.
//
// Variables :  Left_justification() - ���� ����
//              Right_justification() - ������ ����
//              Centered_justification() - ��� ����
//              length_check(int count) - �� ������ ���� Ȯ��
//              char buffer[80] - �����͸� �б� ���� ���� 80�� char�� �迭 ����
//              char stringbuffer[80] - �����͸� ����ϱ� ���� ���� 80�� char�� �迭 ����
//              int i = 0 - �ε����� i ���� �� �ʱ�ȭ
//              ifstream infile - �ܺ��� ���� �޾ƿ���
//              int num = 0 - ó�� �Է��� num �� ���� �� 0���� �ʱ�ȭ
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
using namespace std;

void Left_justification();
void Right_justification();
void Centered_justification();
void length_check(int count);

char buffer[80];        // �����͸� �б� ���� ���� 80�� char�� �迭 ����
char stringbuffer[80];  // �����͸� ����ϱ� ���� ���� 80�� char�� �迭 ����
int i = 0;              // �ε����� i ���� �� �ʱ�ȭ

int main() {
	int num = 0;
	
	while (num != 4) {                                               // 4. Terminate �� �ƴҽ� ��� ����
		cout << "**************************************" << endl;    
		cout << "1. Left     Justification" << endl;                 // ���� ����
		cout << "2. Right    Justification" << endl;                 // ������ ����
		cout << "3. Centered Justification" << endl;                 // ��� ����
		cout << "4. Terminate" << endl << endl;                      // ����

		cout << "Enter your choice : "; cin >> num; cout << endl;    // ���ϴ� ���� Ȥ�� ���ῡ �ش��ϴ� ���� �Է�

		for (int i = 0; i < 8; i++) {                                // �ڸ����� �� �����ֱ� ���� ���ڶ���
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

void Left_justification() {                // ���� ����
    ifstream infile;                       // �ܺ��� ���� �޾ƿ���
    infile.open("hw1.txt", ios::in);
    if (infile.fail()) {
        cout << "������ ���� �����ϴ�" << endl;
        exit(1);
    }

    while (infile.getline(buffer, 80)) {   // �� ������ ����
        while (buffer[i] != '\0') {        // ������ ���ڰ� '\0'�� �ƴ� ������, �� ������ ���� �ƴ� ������
            stringbuffer[i] = buffer[i];   // ����� �迭 stringbuffer�� ������ ����
            i++;                           // �ε��� �� ����.
        }
        stringbuffer[i] = '\0';            // end of line �߰�
        cout << stringbuffer << endl;      // stringbuffer ���
        stringbuffer[0] = '\0';            // ���� ������ ���� �ޱ� ���� stringbuffer�� �ٽ� '\0'���� �ʱ�ȭ
                                           // (* hw1.txt ���� ���� �ʿ䰡 ������, �� ���κ��� �� ������ ª�ٸ� �� �ʿ���)
        i = 0;                             // �ε��� �� i ���� 0���� �ʱ�ȭ
    }
    cout << endl;

    infile.close();
}

void Right_justification() {               // ������ ����         
    ifstream infile;                       // �ܺ��� ���� �޾ƿ���
    infile.open("hw1.txt", ios::in);
    if (infile.fail()) {
        cout << "������ ���� �����ϴ�" << endl;
        exit(1);
    }

    while (infile.getline(buffer, 80)) {   // �� ������ ����
        while (buffer[i] != '\0') {        // ������ ���ڰ� '\0'�� �ƴ� ������, �� ������ ���� �ƴ� ������
            i++;                           // �ε��� �� ����
        }

        length_check(i);                   // �� ������ ���� üũ
        i = 0;                             // �ε��� ���� �ٽ� 0���� �ʱ�ȭ

        while (buffer[i] != '\0') {
            stringbuffer[i] = buffer[i];   // ����� �迭 stringbuffer�� ������ ����.
            i++;                           // �ε��� �� ����
        }

        stringbuffer[i] = '\0';            // end of line �߰�
        cout << stringbuffer << endl;      // stringbuffer ���
        stringbuffer[0] = '\0';            // ���� ������ ���� �ޱ� ���� stringbuffer�� �ٽ� '\0'���� �ʱ�ȭ
        i = 0;                             // �ε��� �� i ���� 0���� �ʱ�ȭ
        
    }
    cout << endl;

    infile.close();
}

void Centered_justification() {            // ��� ����
    int blank_space = 0;                   // ��ĭ ����ؼ� ���� ���� blank_space ����

    ifstream infile;                       // �ܺ��� ���� �޾ƿ���
    infile.open("hw1.txt", ios::in);
    if (infile.fail()) {
        cout << "������ ���� �����ϴ�" << endl;
        exit(1);
    }

    while (infile.getline(buffer, 80)) {   // �� ������ ����
        while (buffer[i] != '\0') {        // ������ ���ڰ� '\0'�� �ƴ� ������, �� ������ ���� �ƴ� ������
            i++;                           // �ε��� �� ����
        }

        blank_space = (79 - i) / 2;        // ��� ������ ���� 2�� ���� ���� ����
        i = 0;                             // �ε��� ���� �ٽ� 0���� �ʱ�ȭ

        for (int j = 0; j <= blank_space; j++)
            cout << ' ';                   // ��ĭ ����ŭ ���� ���

        while (buffer[i] != '\0') {        // ������ ���ڰ� '\0'�� �ƴ� ������, �� ������ ���� �ƴ� ������
            stringbuffer[i] = buffer[i];   // ����� �迭 stringbuffer�� ������ ����
            i++;                           // �ε��� �� ����
        }

        stringbuffer[i] = '\0';            // end of line �߰�
        cout << stringbuffer << endl;      // stringbuffer ���
        stringbuffer[0] = '\0';            // ���� ������ ���� �ޱ� ���� stringbuffer�� �ٽ� '\0'���� �ʱ�ȭ
        i = 0;                             // �ε��� �� i ���� 0���� �ʱ�ȭ
    }

    infile.close();
}

void length_check(int count) {             // �� ������ ���� Ȯ��
    for (int i = 0; i <= 79 - count; i++)   cout << ' ';    // �ִ���� 79���� ������ ���̸� �� ��ŭ ���� ���.
}                             