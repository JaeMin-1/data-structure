////////////////////////////////////////////////////////////////////////
// Name : �����
// Student ID : 20181592
// Program ID : hw2
// Description : �ܺ��� ������ �Է¹޾� �� ���θ��� �������� �������� �Ǵ��ϰ� �ƴ϶�� ������ �˷��ִ� ���α׷�
//
// Algorithm :  �ܺ��� �ؽ�Ʈ ������ �ҷ��� �� ���ξ� ���α׷��� �����Ѵ�
//              check_paren() �Լ��� �����͸� �Ѱܼ� �������ο� �ұ����� ������ ã�Ƴ���
//              �� �������� int match() �Լ��� ��ȣ�� ���� ���θ� Ȯ���ϴ�
//              ���� ���忡 ���� ������ ����Ѵ�
//
// Variables :  int check_paren(char exp[]);      // �������� üũ �Լ�
//              int match(char temp, char exp);   // ��ȣ�� �� ���� �Ǵ� �Լ�
//              int Unbalance = 0;                // ������ ���� ���� ������ ��
//              int Missmatch = 0;                // ��Ī�� ���� ���� ������ ��
//              int balance = 0;                  // �������� �´� ������ ��
//              int Maxsize = 10;                 // ������ ũ�⸦ ���� �� �ʱ�ȭ
//              char stack[10];                   // �������μ� �迭 ����
//              int top;                          // ������ �ε��� ���� ����
//              Stack();                          // ���� ����
//              void push(char val);              // ���ÿ� ���Ҹ� �����ϴ� �Լ�
//              char pop();                       // ���ÿ��� ������ ����Ǿ��ִ� ���Ҹ� ���� �Լ�
//              bool isEmpty();                   // ������ ������� �Ǵ��ϴ� �Լ�
//              Stack::Stack()                    // ���ÿ� top�� -1�� �ʱ�ȭ
//              void Stack::push(char val)        // stack[++top]�� val(�Ű�����) ����
//              char Stack::pop()                 // ���ÿ��� �� ������ ���� ���� �� ���� ����
//              bool Stack::isEmpty()             // top�� -1�̸� 1(��, ����ִ�)�� ����, �ƴϸ� 0(����, ä�����ִ�)�� ����
//              int main()                        // ���� �Լ�    
/////////////////////////////////////////////////////////////////////////

#include <iostream>  
#include <fstream>                // ���� ����� ���̺귯��
#include <cstring>                // strlen ����ϱ� ���� �ҷ���
using namespace std;
int check_paren(char exp[]);      // �������� üũ �Լ�
int match(char temp, char exp);   // ��ȣ�� �� ���� �Ǵ� �Լ�
int Unbalance = 0;                // ������ ���� ���� ������ ��
int Missmatch = 0;                // ��Ī�� ���� ���� ������ ��
int balance = 0;                  // �������� �´� ������ ��

class Stack {
private:
    int Maxsize = 10;             // ������ ũ�⸦ ���� �� �ʱ�ȭ
    char stack[10];               // �������μ� �迭 ����
    int top;                      // ������ �ε��� ���� ����

public:
    Stack();                      // ���� ����
    void push(char val);          // ���ÿ� ���Ҹ� �����ϴ� �Լ�
    char pop();                   // ���ÿ��� ������ ����Ǿ��ִ� ���Ҹ� ���� �Լ�
    bool isEmpty();               // ������ ������� �Ǵ��ϴ� �Լ�
};

Stack::Stack() {
    this->top = -1;               // ���ÿ� top�� -1�� �ʱ�ȭ
}

void Stack::push(char val) {
    this->stack[++top] = val;     // stack[++top]�� val(�Ű�����) ����
}

char Stack::pop() {
    return this->stack[(top)--];  // ���ÿ��� �� ������ ���� ���� �� ���� ����
}

bool Stack::isEmpty() {
    if (top == -1) return 1;      // top�� -1�̸� 1(��, ����ִ�)�� ����, �ƴϸ� 0(����, ä�����ִ�)�� ����
    else return 0;
}

/*
main() �Լ�
    �ܺ� �ؽ�Ʈ ������ �ҷ��ͼ� �� ���ξ� check_paren() �Լ��� �Ѱ��༭ �������� ��������, �ұ������� �������� Ȯ���ϰ�
    �׿� �˸°� ������ ���¸� �����Ѵ�
    �̿��� �ڼ��� ���׵��� �ؿ� ����
*/
int main() {
    ifstream infile;                            // �ҷ��� �ؽ�Ʈ ���� ���� ����
    char buffer[80];
    int i = 0;
    infile.open("hw2.txt", ios::in);            // ���� ����

    cout << "<< HW2:  Balanced Parentheses >>" << endl << endl;
    while (infile.getline(buffer, 80)) {        // �ؽ�Ʈ ������ �����͸� �� ���ξ� �޾ƿ� ���� ����
        i++;                                    // ���� ��ȣ üũ
        cout << "Input Data " << i << ". " << buffer << endl; 
        int validity = check_paren(buffer);     // ������ check_paren�Լ��� �Ѱ���
        if (validity == 1) {                    // 1�̸� �������� ǥ��, 0�̸� �ұ������� ǥ��
            cout << "The Expression is Valid" << endl << endl;
        }
        else cout << "The Expression is Invalid" << endl << endl;
    }
    cout << "Total : " << "Balance : " << balance << "   Unbalance : " << Unbalance << "   MissMatch : " << Missmatch;
    infile.close();                             // ���� �ݱ�
    return 0;
}

/*
check_paren() �Լ�
    �����Լ����� �ؽ�Ʈ ������ �� ������ �Ű������� �޾Ƽ� ��ȣ �������θ� �Ǵ�
    ���ؿ� �հ�ȣ�� �����ϰ� ���� exp[i]�� �ް�ȣ�� �Ǿ����� �հ�ȣ�� pop�� ���� temp�� ������
    temp(�հ�ȣ), exp[i](�ް�ȣ) �� ���Ѵ�.
    �ùٸ� �����̸� �ᱹ ������ ��� �ǹǷ� �̶� balance�� �߰����ش�.
    �̿��� �ڼ��� ���׵��� �ؿ� ����
*/
int check_paren(char exp[]) {
    Stack s;                                      // ���� ����
    char temp;
    for (int i = 0; i < strlen(exp); i++) {       // exp�� �ܺ� ���Ͽ��� �о���� �� ����
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') s.push(exp[i]);    //exp[i]�� �հ�ȣ�϶� ���ÿ� exp[i] ����
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {                  //exp[i]�� �ް�ȣ�϶� 
            if (s.isEmpty()) {    // ������ ����ִٸ� ���� �̷��� �����Ƿ� Unbalance�� �߰�, �ش� �޼��� ���, ������ �Լ� ����
                Unbalance++;
                cout << "The expression has unbalanced parentheses" << endl;
                return 0;
            }
            else {                // ������ ������� �ʴٸ�(=�հ�ȣ�� �����Ѵٸ�)
                temp = s.pop();   // ������ ������ ���� temp�� ��������
                if (!match(temp, exp[i])) {    // match�Լ��� ���� �ƴ϶�� Missmatch�� �߰�, �ش� �޼��� ���, ������ �Լ� ����
                    Missmatch++;
                    cout << "The missmatched parentheses in the expression are " << temp << " and " << exp[i] << endl;
                    return 0;
                }
            }
        }
    }
    if (s.isEmpty()) {         // for���� ���� �� ���� ������ ����ִٸ� balance �߰�, 1(=��)�� ����
        balance++;
        return 1;
    }
    else if (!s.isEmpty()) {   // for���� ���� �� ���� ������ ������� �ʴٸ�, Unbalance �߰�, 0(=����)�� ��ȯ
        Unbalance++;
        cout << "The expression has unbalanced parentheses" << endl;
        return 0;
    }
    return 0;
}

/*
int match() �Լ�
    check_paren �Լ����� ���ÿ� �����ص� ��ȣ�� ���� �ε��� ���� �ش�� ��ȣ�� ���� �̷���� �Ǵ�
    temp�� ������ ������ ��(=ù�Է°�)  [ or { or (, exp�� ) or } or ] �� �ϳ�. [] , {}, () �̷��� ���� �̷�� ���� ���� ����,
    �̸� �����ϰ�� ���� ������ ����
*/
int match(char temp, char exp) {
    if (temp == '[' && exp == ']') return true;
    else if (temp == '{' && exp == '}') return true;
    else if (temp == '(' && exp == ')') return true;
    else return false;
}