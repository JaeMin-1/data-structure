////////////////////////////////////////////////////////////////////////
// Name : 김재민
// Student ID : 20181592
// Program ID : hw4
// Description : 외부의 파일에서 그래프를 가져와서 깊이 우선 탐색(DFS)를 실행하여 그래프와 DFS 결과를 출력하는 프로그램
//
// Algorithm :  외부의 파일에서 그래프의 정보를 가져온다
//              그래프의 정보를 토대로 buildList() 함수로 그래프를 만든다
//              만들어진 그래프를 dfs() 함수로 깊이 우선 탐색을 실행한다
//              그래프와 깊이 우선 탐색 결과를 각각 출력한다
//
// Variables :  char data;                           //노드의 원소 선언
//              Node *link;                          //노드의 link 선언
//              Node(char value)                     //노드 초기화 및 선언
//              Node *root;                          //root 노드 선언
//              Node *head;                          //head 노드 선언
//              Node *graph[10] = {NULL};            //graph 모든 원소 null로 초기화 및 선언
//              bool visited[10] = {false};          //visited 모든 원소 false로 초기화 및 선언
//              List() { head = 0; };                //head를 0으로 초기화
//              void print_graph();                  //graph를 출력
//              void buildList(char buffer[], int line);   //외부의 그래프 정보를 가져와 그래프 생성
//              void dfs(int v);                           //그래프에 대해 깊이 우선 탐색 실행
//              int main()                           //외부 파일을 읽어와 buildList()와 dfs()를 실행 후 결과를 출력
/////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
using namespace std;

class Node {
private:
    char data;                           //노드의 원소 선언
    Node *link;                          //노드의 link 선언

public:
    Node(char value) {                   //노드 초기화 및 선언
        data = value;
        link = '\0';
    }
    friend class List;
};

class List {
private:
    Node *root;                          //root 노드 선언
    Node *head;                          //head 노드 선언
    Node *graph[10] = {NULL};            //graph 모든 원소 null로 초기화 및 선언
    bool visited[10] = {false};          //visited 모든 원소 false로 초기화 및 선언

public:
    List() { head = 0; };                //head를 0으로 초기화
    void print_graph();                  //graph를 출력
    void buildList(char buffer[], int line);   //외부의 그래프 정보를 가져와 그래프 생성
    void dfs(int v);                           //그래프에 대해 깊이 우선 탐색 실행
};

/*
buildList() 함수 : graph 생성
    - 각각 첫 head를 저장하고 각각의 head 마다 next node를 연결하여 singly linked List를 만든다
*/
void List::buildList(char buffer[], int line) {
    int i = 0;
    char temp = buffer[i++];             //각 라인별 데이터로 인접리스트 생성
    head = new Node(temp);               //각 리스트의 첫번째 head node 생성
    graph[line] = head;                  //head 노드 저장

    Node *q = head;                      //q for moving
    while (buffer[i] != '\0') {
        temp = buffer[i++];
        Node *t = new Node(temp);        //create next node 생성
        q->link = t;
        q = q->link;                     //make singly linked List
    }
}

/*
print_graph() 함수 : graph 출력
    - graph의 원소들, 즉 각 head node 들이 생성한 각각의 singly linked List를 차례로 출력한다
*/
void List::print_graph() {
    Node *p;
    for (int i = 0; graph[i] != 0; i++) {
        cout << "graph[" << graph[i]->data << "] -> ";
        for (p = graph[i]->link; p != NULL; p = p->link) {
            cout << p->data << " ";
        }
        cout << endl;
    }
}

/*
dfs() 함수 :  buildList() 함수를 통해 만들어진 graph에 대해 깊이 우선 탐색을 실행 후 출력
    - 그래프의 각 원소들, 즉 head node 들의 방문여부를 판단해가며 순차적으로 시행
*/
void List::dfs(int v) {
    Node *w;
    visited[v] = true;
    cout << v << " -> ";
    for (w = graph[v]; w != NULL; w = w->link) {
        int idx = (int)(w->data) - '0';
        if (!visited[idx]) {
            dfs(idx);
        }
    }
}

/*
main() 함수 : 각각 다른 두 외부 파일을 불러와 생성한 각각의 객체인 list1과 list2를 통해 프로그램을 수행한다
*/
int main() {
    List list1;
    int line1 = 0;

    ifstream infile1;
    char buffer1[80];
    infile1.open("hw4-1.txt", ios::in);

    while (infile1.getline(buffer1, 80)){
        list1.buildList(buffer1, line1);
        line1++;
    }
    cout << " <<    Graph data 1    >>" << endl << endl;
    list1.print_graph(); cout << endl;
    cout << "    depth first search result:" << endl;
    list1.dfs(0); cout << endl << endl << endl;
    infile1.close();

    List list2;
    int line2 = 0;
    ifstream infile2;
    char buffer2[80];
    infile2.open("hw4-2.txt", ios::in);

    while (infile2.getline(buffer2, 80)){
        list2.buildList(buffer2, line2);
        line2++;
    }
    cout << " <<    Graph data 2    >>" << endl << endl;
    list2.print_graph(); cout << endl;
    cout << "    depth first search result:" << endl;
    list2.dfs(0);
    infile2.close();
    
    return 0;
}