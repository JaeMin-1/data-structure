#include <iostream>
#include <fstream>
using namespace std;

class Node {
private:
    char data;
    Node *link;

public:
    Node(char value)
    {
        data = value;
        link = '\0';
    }
    friend class List;
};

class List {
private:
    Node *root;
    Node *head;
    Node *graph[10] = {NULL};
    bool visited[10] = {false};

public:
    List() { head = 0; };
    void print_graph();
    void buildList(char buffer[], int line);
    void dfs(int v);
};

void List::buildList(char buffer[], int line) {
    int i = 0;
    char temp = buffer[i++]; // 각 라인별 데이터로 인접리스트 생성
    head = new Node(temp);   // 각 리스트의 첫번째 head node 생성
    graph[line] = head;      // head 노드 저장

    Node *q = head; // q for moving
    while (buffer[i] != '\0') {
        temp = buffer[i++];
        Node *t = new Node(temp); // create next node 생성
        q->link = t;
        q = q->link; // & make singly linked List
    }
}

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

void List::dfs(int v) {
    Node *w;
    visited[v] = true;
    cout << v << " -> ";
    for (w = graph[v]; w != NULL; w = w->link) {
        int index = (int)(w->data) - '0';
        if (!visited[index]) {
            dfs(index);
        }
    }
}

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