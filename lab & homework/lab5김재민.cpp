////////////////////////////////////////////////////////////////////////
// Lab5 : Infix-to-Postfix conversion & Evaluation
// Name : ±Ë¿ÁπŒ
// ID : 20181592
/////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

class Stack {
private:
    int Maxsize = 10;
    char stack[10];
    int top;

public:
    Stack();
    void push(char val);
    char pop();
    bool isEmpty();
    bool isFull();
};

Stack::Stack() {
    this->top = -1;
}

void Stack::push(char val) {
    if (top >= this->Maxsize - 1) {
        cout << "Stack is Full!";
        return;
    }
    this->stack[++top] = val;
}

char Stack::pop() {
    if (top == -1) {
        cout << "Stack is Empty!";
        return -1;
    }
    return this->stack[(top)--];
}

bool Stack::isEmpty() {
    if (top == -1) return true;
    else return false;
}

bool Stack::isFull() {
    if (top == this->Maxsize - 1) return true;
    else return false;
}

class StackI {
private:
    int Maxsize = 100;
    int stack[100];
    int top;

public:
    StackI();
    void push(int val);
    int pop();
    bool isEmpty();
    bool isFull();
};

StackI::StackI() {
    this->top = -1;
}

void StackI::push(int val) {
    if (top >= this->Maxsize - 1) {
        cout << "Stack is Full!";
        return;
    }
    this->stack[++top] = val;
}

int StackI::pop() {
    if (top == -1) {
        cout << "Stack is Empty!";
        return -1;
    }
    return (int)this->stack[(top)--];
}

bool StackI::isEmpty() {
    if (top == -1) return true;
    else return false;
}

bool StackI::isFull() {
    if (top == this->Maxsize - 1) return true;
    else return false;
}

bool is_operand(char a) {
    switch (a) {
    case '+': return false; break;
    case '-': return false; break;
    case '*': return false; break;
    case '/': return false; break;
    case '(': return false; break;
    case ')': return false; break;

    default: return true; break;
    }
}

int Prec(char a) {
    switch (a) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

void Posteval(char postbuffer[]) {
    int i = 0;
    StackI stack = StackI();
    int p1, p2;
    int result = 0;
    int finaldata;
    while (postbuffer[i] != '\0') {
        if (is_operand(postbuffer[i])) {
            stack.push(postbuffer[i] - '0');
            i++;
        }
        else {
            p2 = stack.pop();
            p1 = stack.pop();

            switch (postbuffer[i])
            {
            case '+':
                result = p1 + p2;
                break;
            case '-':
                result = p1 - p2;
                break;
            case '*':
                result = p1 * p2;
                break;
            case '/':
                result = p1 / p2;
                break;

            default: cout << "ERROR in expression"; break;
            } i++; stack.push(result);
        }
    }
    finaldata = stack.pop();
    cout << endl << "The final result : " << finaldata << endl << endl;
}

void postconv(char fil[]) {
    int i = 0;
    char top_element = '(';
    Stack stack = Stack();
    char tmp;
    char postfix[10];
    int j = 0;
    while (fil[i] != '\0')
    {
        if (is_operand(fil[i])) {
            cout << fil[i];
            postfix[j++] = fil[i];
            i++;
        }
        else {
            switch (fil[i])
            {
            case '(':
                stack.push(fil[i]);
                top_element = fil[i];
                i++; break;
            case ')':
                tmp = stack.pop();
                while (tmp != '(') {
                    cout << tmp;
                    postfix[j++] = tmp;
                    tmp = stack.pop();
                } i++; break;
            default:
                if (Prec(fil[i]) > Prec(top_element)) {
                    stack.push(fil[i]);
                    top_element = fil[i];
                }
                else {
                    tmp = stack.pop();
                    postfix[j++] = tmp;
                    cout << tmp;
                    stack.push(fil[i]);
                    top_element = fil[i];

                } i++; break;
            }
        }
    }
    while (!stack.isEmpty()) {
        tmp = stack.pop();
        postfix[j++] = tmp;
        cout << tmp;
    }
    cout << endl;
    postfix[j++] = '\0';
    Posteval(postfix);
}

void infix_ex(char buffer[]) {
    int i = 0;
    cout << "Infix expression : ";
    while (buffer[i] != '\0') cout << buffer[i++];
    cout << "    The Postfix conversion : ";
    postconv(buffer);
}

int main() {
    char fil[80];
    fstream infile;
    infile.open("lab5.txt", ios::in);
    while (infile.getline(fil, 80)) {
        infix_ex(fil);
    }
    return 0;
}