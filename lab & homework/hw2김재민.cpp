////////////////////////////////////////////////////////////////////////
// Name : 김재민
// Student ID : 20181592
// Program ID : hw2
// Description : 외부의 파일을 입력받아 각 라인마다 균형적인 문장인지 판단하고 아니라면 이유를 알려주는 프로그램
//
// Algorithm :  외부의 텍스트 파일을 불러와 한 라인씩 프로그램을 시작한다
//              check_paren() 함수로 데이터를 넘겨서 균형여부와 불균형시 이유를 찾아낸다
//              그 과정에서 int match() 함수가 괄호의 균형 여부를 확인하다
//              이후 문장에 대한 정보를 출력한다
//
// Variables :  int check_paren(char exp[]);      // 균형여부 체크 함수
//              int match(char temp, char exp);   // 괄호의 쌍 여부 판단 함수
//              int Unbalance = 0;                // 균형이 맞지 않은 데이터 수
//              int Missmatch = 0;                // 매칭이 맞지 않은 데이터 수
//              int balance = 0;                  // 벨런스가 맞는 데이터 수
//              int Maxsize = 10;                 // 스택의 크기를 선언 및 초기화
//              char stack[10];                   // 스택으로서 배열 선언
//              int top;                          // 스택의 인덱스 변수 선언
//              Stack();                          // 스택 생성
//              void push(char val);              // 스택에 원소를 저장하는 함수
//              char pop();                       // 스택에서 마지막 저장되어있는 원소를 빼는 함수
//              bool isEmpty();                   // 스택이 비었는지 판단하는 함수
//              Stack::Stack()                    // 스택에 top을 -1로 초기화
//              void Stack::push(char val)        // stack[++top]에 val(매개변수) 저장
//              char Stack::pop()                 // 스택에서 맨 마지막 값을 빼서 그 값을 리턴
//              bool Stack::isEmpty()             // top이 -1이면 1(참, 비어있다)을 리턴, 아니면 0(거짓, 채워져있다)을 리턴
//              int main()                        // 메인 함수    
/////////////////////////////////////////////////////////////////////////

#include <iostream>  
#include <fstream>                // 파일 입출력 라이브러리
#include <cstring>                // strlen 사용하기 위해 불러옴
using namespace std;
int check_paren(char exp[]);      // 균형여부 체크 함수
int match(char temp, char exp);   // 괄호의 쌍 여부 판단 함수
int Unbalance = 0;                // 균형이 맞지 않은 데이터 수
int Missmatch = 0;                // 매칭이 맞지 않은 데이터 수
int balance = 0;                  // 벨런스가 맞는 데이터 수

class Stack {
private:
    int Maxsize = 10;             // 스택의 크기를 선언 및 초기화
    char stack[10];               // 스택으로서 배열 선언
    int top;                      // 스택의 인덱스 변수 선언

public:
    Stack();                      // 스택 생성
    void push(char val);          // 스택에 원소를 저장하는 함수
    char pop();                   // 스택에서 마지막 저장되어있는 원소를 빼는 함수
    bool isEmpty();               // 스택이 비었는지 판단하는 함수
};

Stack::Stack() {
    this->top = -1;               // 스택에 top을 -1로 초기화
}

void Stack::push(char val) {
    this->stack[++top] = val;     // stack[++top]에 val(매개변수) 저장
}

char Stack::pop() {
    return this->stack[(top)--];  // 스택에서 맨 마지막 값을 빼서 그 값을 리턴
}

bool Stack::isEmpty() {
    if (top == -1) return 1;      // top이 -1이면 1(참, 비어있다)을 리턴, 아니면 0(거짓, 채워져있다)을 리턴
    else return 0;
}

/*
main() 함수
    외부 텍스트 파일을 불러와서 한 라인씩 check_paren() 함수로 넘겨줘서 균형적인 문장인지, 불균형적인 문장인지 확인하고
    그에 알맞게 문장의 상태를 설명한다
    이외의 자세한 사항들은 밑에 설명
*/
int main() {
    ifstream infile;                            // 불러올 텍스트 파일 변수 선언
    char buffer[80];
    int i = 0;
    infile.open("hw2.txt", ios::in);            // 파일 열기

    cout << "<< HW2:  Balanced Parentheses >>" << endl << endl;
    while (infile.getline(buffer, 80)) {        // 텍스트 파일의 데이터를 한 라인씩 받아올 동안 수행
        i++;                                    // 라인 번호 체크
        cout << "Input Data " << i << ". " << buffer << endl; 
        int validity = check_paren(buffer);     // 라인을 check_paren함수로 넘겨줌
        if (validity == 1) {                    // 1이면 균형적인 표현, 0이면 불균형적인 표현
            cout << "The Expression is Valid" << endl << endl;
        }
        else cout << "The Expression is Invalid" << endl << endl;
    }
    cout << "Total : " << "Balance : " << balance << "   Unbalance : " << Unbalance << "   MissMatch : " << Missmatch;
    infile.close();                             // 파일 닫기
    return 0;
}

/*
check_paren() 함수
    메인함수에서 텍스트 파일의 한 라인을 매개변수로 받아서 괄호 균형여부를 판단
    스텍에 앞괄호를 저장하고 이후 exp[i]가 뒷괄호가 되었을때 앞괄호를 pop을 통해 temp로 보내서
    temp(앞괄호), exp[i](뒷괄호) 를 비교한다.
    올바른 문장이면 결국 스택이 비게 되므로 이때 balance를 추가해준다.
    이외의 자세한 사항들은 밑에 설명
*/
int check_paren(char exp[]) {
    Stack s;                                      // 스택 선언
    char temp;
    for (int i = 0; i < strlen(exp); i++) {       // exp는 외부 파일에서 읽어들인 한 라인
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') s.push(exp[i]);    //exp[i]가 앞괄호일때 스택에 exp[i] 저장
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {                  //exp[i]가 뒷괄호일때 
            if (s.isEmpty()) {    // 스택이 비어있다면 쌍을 이루지 않으므로 Unbalance를 추가, 해당 메세지 출력, 리턴후 함수 종료
                Unbalance++;
                cout << "The expression has unbalanced parentheses" << endl;
                return 0;
            }
            else {                // 스택이 비어있지 않다면(=앞괄호가 존재한다면)
                temp = s.pop();   // 스택의 마지막 값을 temp로 가져오기
                if (!match(temp, exp[i])) {    // match함수가 참이 아니라면 Missmatch를 추가, 해당 메세지 출력, 리턴후 함수 종료
                    Missmatch++;
                    cout << "The missmatched parentheses in the expression are " << temp << " and " << exp[i] << endl;
                    return 0;
                }
            }
        }
    }
    if (s.isEmpty()) {         // for문이 끝난 후 만약 스택이 비어있다면 balance 추가, 1(=참)을 리턴
        balance++;
        return 1;
    }
    else if (!s.isEmpty()) {   // for문이 끝난 후 만약 스택이 비어있지 않다면, Unbalance 추가, 0(=거짓)을 반환
        Unbalance++;
        cout << "The expression has unbalanced parentheses" << endl;
        return 0;
    }
    return 0;
}

/*
int match() 함수
    check_paren 함수에서 스택에 저장해둔 괄호와 현재 인덱스 값에 해당된 괄호가 쌍을 이루는지 판단
    temp는 스택의 마지막 값(=첫입력값)  [ or { or (, exp는 ) or } or ] 중 하나. [] , {}, () 이렇게 쌍을 이루는 경우는 참을 리턴,
    이를 제외하고는 전부 거짓을 리턴
*/
int match(char temp, char exp) {
    if (temp == '[' && exp == ']') return true;
    else if (temp == '{' && exp == '}') return true;
    else if (temp == '(' && exp == ')') return true;
    else return false;
}