////////////////////////////////////////////////////////////////////////
// Name : 김재민
// Student ID : 20181592
// Program ID : hw3
// Description : 리스트에 원소를 추가하고 삭제하는 등 여러 옵션을 선택해 리스트를 편집할 수 있는 프로그램
//
// Algorithm :  실행할 함수에 해당하는 번호를 입력하고, 필요시엔 숫자도 입력한다
//              번호에 따른 함수들이 실행되고 리스트는 함수의 명령에 따라 편집된다
//              매번 함수 실행후에 현재 리스트를 출력한다 (Quit 함수 제외)
//
// Variables :  Type val;                         //노드의 원소 선언
//              Node* next;                       //노드의 next 선언
//              Node* prev;                       //노드의 prev 선언
//              Node(Type data) { val = data; next = 0; prev = 0; } //노드 초기화 및 선언
//              Node* head;                       //head 노드 선언
//              Node* current;                    //current 노드 선언
//              List() { head = 0; current = 0; } //head와 current를 0으로 초기화
//              ~List();                          //Doubly Linked List를 전부 비움
//              void insertAfter(Type);           //current 뒤에 새로운 노드를 insert
//              void insertBefore(Type);          //current 앞에 새로운 노드를 insert
//              void insertFirst(Type);           //맨 앞에 새로운 노드를 insert
//              void insertLast(Type);            //맨 뒤에 새로운 노드를 insert
//              void Deletecurrent();             //현재 current 노드를 삭제
//              void Locatecurrent(int);          //현재 current 노드를 사용자가 새로 설정
//              void Updatecurrent(int);          //현재 current 노드의 값을 새로 저장
//              void DisplayList();               //현재 Doubly Linked List를 출력
//              void Quit();                      //모든 노드를 지우고 프로그램 종료
//              int main()                        //실행할 함수에 해당하는 번호를 입력하고, 필요시엔 숫자도 입력하여 각각의 함수를 실행하여 프로그램을 진행한다
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;
typedef int Type;

class Node {
private:
    Type val;                         //노드의 원소 선언
    Node* next;                       //노드의 next 선언
    Node* prev;                       //노드의 prev 선언
    Node(Type data) { val = data; next = 0; prev = 0; } //노드 초기화 및 선언
    friend class List;
};

class List {
private:
    Node* head;                       //head 노드 선언
    Node* current;                    //current 노드 선언
public:
    List() { head = 0; current = 0; } //head와 current를 0으로 초기화
    ~List();                          //Doubly Linked List를 전부 비움
    void insertAfter(Type);           //current 뒤에 새로운 노드를 insert
    void insertBefore(Type);          //current 앞에 새로운 노드를 insert
    void insertFirst(Type);           //맨 앞에 새로운 노드를 insert
    void insertLast(Type);            //맨 뒤에 새로운 노드를 insert
    void Deletecurrent();             //현재 current 노드를 삭제
    void Locatecurrent(int);          //현재 current 노드를 사용자가 새로 설정
    void Updatecurrent(int);          //현재 current 노드의 값을 새로 저장
    void DisplayList();               //현재 Doubly Linked List를 출력
    void Quit();                      //모든 노드를 지우고 프로그램 종료
};

/*
~List() 함수 : Doubly Linked List를 전부 비움
    - 원소들을 처음부터 끝까지 순서대로 삭제함
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
insertAfter() 함수 : current 노드 뒤에 새로운 노드를 insert
    - 새로 넣을 노드 temp를 선언 및 초기화
    - if, head가 NULL이면, 즉 리스트가 비어있으면 temp를 head로 둔다
    - else if, current의 next가 0이 아니라면 temp를 current와 current의 next 사이에 삽입
    - else, current가 마지막 노드일 경우 current의 next는 temp
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
insertBefore() 함수 : current 노드 앞에 새로운 노드를 insert
    - 새로 넣을 노드 temp를 선언 및 초기화
    - if, head가 NULL이면, 즉 리스트가 비어있으면 temp를 head로 둔다
    - else if, current가 head라면 temp를 head 앞에 삽입
    - else, current의 prev가 0이 아니라면 current의 prev는 temp
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
insertFirst 함수 : 맨 앞에 새로운 노드를 insert
 - 새로 넣을 노드 temp를 선언 및 초기화
 - if, head가 NULL이면 temp를 head로 둔다
 - else, temp를 head로 둔다
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
insertLast 함수 : 맨 뒤에 새로운 노드를 insert
 - 새로 넣을 노드 temp를 선언 및 초기화
 - if, head가 NULL이면 temp를 head로 둔다
 - else, temp를 마지막으로 둔다
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
 Deletecurrent 함수 : 현재 current 노드를 삭제
    - Node *p = head => p는 Doubly Linked List의 첫부분 부터 시작해서, 마지막 노드까지 이동하기 위해 선언
    - if, head가 NULL이면 아무것도 x (DisplayList 함수에서 리스트가 비었다는 메세지 출력)
    - else if, current가 head일 경우 head는 head의 next로, current는 current의 next로 초기화
    - else if, current의 next가 0일 경우 current의 prev를 current로 둔 후 curren의 next를 0으로 초기화
    - else, current가 중간일 경우 current의 prev와 current의 next가 이어지도록 한다.
    - 마지막으로 head를 새로운 current로 지정
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
 Locatecurrent 함수 : 현재 current 노드를 새로 설정
    - Node *p = head => p는 Doubly Linked List의 첫부분 부터 시작해서, 마지막 노드까지 이동하기 위해 선언
    - p를 Linked List의 끝까지 이동하면서, count도 같이 증가
    - count는 Linked List의 길이를 저장하고 입력받은 num이 count보다 클 경우 에러 메세지 출력
    - num이 count보다 작을 경우, num번째 노드와 값을 출력
    - 마지막으로 temp를 새로운 current로 지정
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
            count = 1;    //num번째 자리를 찾기위해 count 초기화 후 while문 진입          
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
Updatecurrent 함수 : 현재 current 노드의 값을 새로 저장
    - 입력한 숫자를 새로운 current로 변경
*/
void List::Updatecurrent(int num) {
    if (head != 0) {
        current->val = num;
    }
}

/*
DisplayList 함수 : 현재 Doubly Linked List를 출력
    -if, 리스트가 비었으면 비었다는 메세지 출력
    -else. 리스트가 존재한다면 리스트 출력
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
Quit 함수 : 모든 노드를 지우고 프로그램 종료
    - 전부 비우고 main함수의 while문을 탈출하여 프로그램 종료(main 함수에서 break; 을 통해 구현)
*/
void List::Quit() {
    List::~List();
}

/*
main 함수
    - 실행할 함수에 해당하는 번호를 입력하고, 필요시엔 숫자도 입력하여 각각의 함수를 실행하여 프로그램을 진행한다
*/
int main() {
    List l1;
    int command = 0;        //실행하고 싶은 함수를 실행하기 위해 선언 및 초기화
    int num = 0;            //함수 실행에 필요한 숫자를 입력하기 위해 선언 및 초기화
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
            break;                              //Quit 실행시 프로그램 종료
        }
        else {
            cout << "bad command" << endl;      //위 커맨드 외에 입력 시 에러메세지 출력
            continue;
        }
    }
    return 0;
}