////////////////////////////////////////////////////////////////////////
// Name : �����
// Student ID : 20181592
// Program ID : hw3
// Description : ����Ʈ�� ���Ҹ� �߰��ϰ� �����ϴ� �� ���� �ɼ��� ������ ����Ʈ�� ������ �� �ִ� ���α׷�
//
// Algorithm :  ������ �Լ��� �ش��ϴ� ��ȣ�� �Է��ϰ�, �ʿ�ÿ� ���ڵ� �Է��Ѵ�
//              ��ȣ�� ���� �Լ����� ����ǰ� ����Ʈ�� �Լ��� ��ɿ� ���� �����ȴ�
//              �Ź� �Լ� �����Ŀ� ���� ����Ʈ�� ����Ѵ� (Quit �Լ� ����)
//
// Variables :  Type val;                         //����� ���� ����
//              Node* next;                       //����� next ����
//              Node* prev;                       //����� prev ����
//              Node(Type data) { val = data; next = 0; prev = 0; } //��� �ʱ�ȭ �� ����
//              Node* head;                       //head ��� ����
//              Node* current;                    //current ��� ����
//              List() { head = 0; current = 0; } //head�� current�� 0���� �ʱ�ȭ
//              ~List();                          //Doubly Linked List�� ���� ���
//              void insertAfter(Type);           //current �ڿ� ���ο� ��带 insert
//              void insertBefore(Type);          //current �տ� ���ο� ��带 insert
//              void insertFirst(Type);           //�� �տ� ���ο� ��带 insert
//              void insertLast(Type);            //�� �ڿ� ���ο� ��带 insert
//              void Deletecurrent();             //���� current ��带 ����
//              void Locatecurrent(int);          //���� current ��带 ����ڰ� ���� ����
//              void Updatecurrent(int);          //���� current ����� ���� ���� ����
//              void DisplayList();               //���� Doubly Linked List�� ���
//              void Quit();                      //��� ��带 ����� ���α׷� ����
//              int main()                        //������ �Լ��� �ش��ϴ� ��ȣ�� �Է��ϰ�, �ʿ�ÿ� ���ڵ� �Է��Ͽ� ������ �Լ��� �����Ͽ� ���α׷��� �����Ѵ�
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;
typedef int Type;

class Node {
private:
    Type val;                         //����� ���� ����
    Node* next;                       //����� next ����
    Node* prev;                       //����� prev ����
    Node(Type data) { val = data; next = 0; prev = 0; } //��� �ʱ�ȭ �� ����
    friend class List;
};

class List {
private:
    Node* head;                       //head ��� ����
    Node* current;                    //current ��� ����
public:
    List() { head = 0; current = 0; } //head�� current�� 0���� �ʱ�ȭ
    ~List();                          //Doubly Linked List�� ���� ���
    void insertAfter(Type);           //current �ڿ� ���ο� ��带 insert
    void insertBefore(Type);          //current �տ� ���ο� ��带 insert
    void insertFirst(Type);           //�� �տ� ���ο� ��带 insert
    void insertLast(Type);            //�� �ڿ� ���ο� ��带 insert
    void Deletecurrent();             //���� current ��带 ����
    void Locatecurrent(int);          //���� current ��带 ����ڰ� ���� ����
    void Updatecurrent(int);          //���� current ����� ���� ���� ����
    void DisplayList();               //���� Doubly Linked List�� ���
    void Quit();                      //��� ��带 ����� ���α׷� ����
};

/*
~List() �Լ� : Doubly Linked List�� ���� ���
    - ���ҵ��� ó������ ������ ������� ������
*/
List::~List() {
    Node* p;

    while (head != 0) {
        p = head;
        head = head->next;
        delete p;
    }
}

/*
insertAfter() �Լ� : current ��� �ڿ� ���ο� ��带 insert
    - ���� ���� ��� temp�� ���� �� �ʱ�ȭ
    - if, head�� NULL�̸�, �� ����Ʈ�� ��������� temp�� head�� �д�
    - else if, current�� next�� 0�� �ƴ϶�� temp�� current�� current�� next ���̿� ����
    - else, current�� ������ ����� ��� current�� next�� temp
*/
void List::insertAfter(Type data) {
    Node* temp = new Node(data);

    if (head == NULL) head = temp;
    else if (current->next != 0) {
        temp->next = current->next; 
        temp->prev = current;       
        current->next->prev = temp; 
        current->next = temp;       
    }
    else {
        current->next = temp;       
        temp->prev = current;       
    }
    current = temp;              
}

/*
insertBefore() �Լ� : current ��� �տ� ���ο� ��带 insert
    - ���� ���� ��� temp�� ���� �� �ʱ�ȭ
    - if, head�� NULL�̸�, �� ����Ʈ�� ��������� temp�� head�� �д�
    - else if, current�� head��� temp�� head �տ� ����
    - else, current�� prev�� 0�� �ƴ϶�� current�� prev�� temp
*/
void List::insertBefore(Type data) {
    Node* temp = new Node(data);

    if (head == 0) head = temp;
    else if (current == head) {   
        temp->next = head;          
        head->prev = temp;          
        head = temp;                
    }
    else {
        temp->next = current;      
        temp->prev = current->prev; 
        current->prev->next = temp; 
        current->prev = temp;       
    }
    current = temp;         
}

/*
insertFirst �Լ� : �� �տ� ���ο� ��带 insert
 - ���� ���� ��� temp�� ���� �� �ʱ�ȭ
 - if, head�� NULL�̸� temp�� head�� �д�
 - else, temp�� head�� �д�
*/
void List::insertFirst(Type data) {
    Node* temp = new Node(data);

    if (head == NULL) head = temp;
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    current = temp;  
}

/*
insertLast �Լ� : �� �ڿ� ���ο� ��带 insert
 - ���� ���� ��� temp�� ���� �� �ʱ�ȭ
 - if, head�� NULL�̸� temp�� head�� �д�
 - else, temp�� ���������� �д�
*/
void List::insertLast(Type data) {
    Node* temp = new Node(data);
    Node* p = head;

    if (head == NULL) head = temp;
    else {
        while (p->next != 0) {  
            p = p->next;       
        }
        p->next = temp;         
        temp->prev = p;         
    }
    current = temp;            
}

/*
 Deletecurrent �Լ� : ���� current ��带 ����
    - Node *p = head => p�� Doubly Linked List�� ù�κ� ���� �����ؼ�, ������ ������ �̵��ϱ� ���� ����
    - if, head�� NULL�̸� �ƹ��͵� x (DisplayList �Լ����� ����Ʈ�� ����ٴ� �޼��� ���)
    - else if, current�� head�� ��� head�� head�� next��, current�� current�� next�� �ʱ�ȭ
    - else if, current�� next�� 0�� ��� current�� prev�� current�� �� �� curren�� next�� 0���� �ʱ�ȭ
    - else, current�� �߰��� ��� current�� prev�� current�� next�� �̾������� �Ѵ�.
    - ���������� head�� ���ο� current�� ����
*/
void List::Deletecurrent() {
    Node* p = head;

    if (head == NULL);
    else if (current == head) {
        head = head->next;
        current = current->next;
    }
    else if (current->next == 0) {
        current = current->prev;
        current->next = 0;
    }
    else {
        while (p->next != current) {     
            p = p->next;                  
        }
        p->next = current->next;         
        current->next->prev = p;         
    }
    current = head;                       
}

/*
 Locatecurrent �Լ� : ���� current ��带 ���� ����
    - Node *p = head => p�� Doubly Linked List�� ù�κ� ���� �����ؼ�, ������ ������ �̵��ϱ� ���� ����
    - p�� Linked List�� ������ �̵��ϸ鼭, count�� ���� ����
    - count�� Linked List�� ���̸� �����ϰ� �Է¹��� num�� count���� Ŭ ��� ���� �޼��� ���
    - num�� count���� ���� ���, num��° ���� ���� ���
    - ���������� temp�� ���ο� current�� ����
*/
void List::Locatecurrent(int num) {
    Node* p = head;
    Node* temp = 0;
    int count = 1; 
    if (head == 0);
    else {
        while (p->next != 0) {     
            p = p->next;
            count++;
        }

        if (count < num) cout << "No such a line!" << endl;        
        else {
            p = head;                 
            count = 1;    //num��° �ڸ��� ã������ count �ʱ�ȭ �� while�� ����          
            while (count <= num) {     
                if (count == num) { temp = p; break; }   
                p = p->next;
                count++;
            }
            cout << num << "*     " << temp->val << endl;
            current = temp;    
        }
    }
}

/*
Updatecurrent �Լ� : ���� current ����� ���� ���� ����
    - �Է��� ���ڸ� ���ο� current�� ����
*/
void List::Updatecurrent(int num) {
    if (head != 0) {
        current->val = num;
    }
}

/*
DisplayList �Լ� : ���� Doubly Linked List�� ���
    -if, ����Ʈ�� ������� ����ٴ� �޼��� ���
    -else. ����Ʈ�� �����Ѵٸ� ����Ʈ ���
*/
void List::DisplayList() {
    Node* p;
    if (head == 0) cout << "List is empty!\n";
    else {
        p = head;
        cout << "--- List ---\n";
        for (int i = 1; p != 0; i++) {
            if (p != current)  cout << setw(5) << i << " : " << p->val << endl;
            else cout << setw(5) << i << " * " << p->val << endl;
            p = p->next;
        }
    }
}

/*
Quit �Լ� : ��� ��带 ����� ���α׷� ����
    - ���� ���� main�Լ��� while���� Ż���Ͽ� ���α׷� ����(main �Լ����� break; �� ���� ����)
*/
void List::Quit() {
    List::~List();
}

/*
main �Լ�
    - ������ �Լ��� �ش��ϴ� ��ȣ�� �Է��ϰ�, �ʿ�ÿ� ���ڵ� �Է��Ͽ� ������ �Լ��� �����Ͽ� ���α׷��� �����Ѵ�
*/
int main() {
    List l1;
    int command = 0;        //�����ϰ� ���� �Լ��� �����ϱ� ���� ���� �� �ʱ�ȭ
    int num = 0;            //�Լ� ���࿡ �ʿ��� ���ڸ� �Է��ϱ� ���� ���� �� �ʱ�ȭ
    while (true) {
        cout << "Command : 1)insert-after  2)insert-before  3)insert-first  4)insert-last  5)deletecurrent  6)locatecurrent  7)updatecurrent  8)displaylist  9)quit => ";
        cin >> command;
        if (command == 1) {
            cout << "enter a data to insert => ";
            cin >> num;
            l1.insertAfter(num);
            l1.DisplayList();
        }
        else if (command == 2) {
            cout << "enter a data to insert => ";
            cin >> num;
            l1.insertBefore(num);
            l1.DisplayList();
        }
        else if (command == 3) {
            cout << "enter a data to insert => ";
            cin >> num;
            l1.insertFirst(num);
            l1.DisplayList();
        }
        else if (command == 4) {
            cout << "enter a data to insert => ";
            cin >> num;
            l1.insertLast(num);
            l1.DisplayList();
        }
        else if (command == 5) {
            l1.Deletecurrent();
            l1.DisplayList();
        }
        else if (command == 6) {
            cout << "Enter a position to locate => ";
            cin >> num;
            l1.Locatecurrent(num);
            l1.DisplayList();
        }
        else if (command == 7) {
            cout << "Enter a data to update => ";
            cin >> num;
            l1.Updatecurrent(num);
            l1.DisplayList();
        }
        else if (command == 8) {
            l1.DisplayList();
        }
        else if (command == 9) {
            l1.Quit();
            break;                              //Quit ����� ���α׷� ����
        }
        else {
            cout << "bad command" << endl;      //�� Ŀ�ǵ� �ܿ� �Է� �� �����޼��� ���
            continue;
        }
    }
    return 0;
}