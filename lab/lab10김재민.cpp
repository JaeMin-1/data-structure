////////////////////////////////////////////////////////////////////////
// Lab10 : Graph Search - (BFS)
// Name : 김재민
// ID : 20181592
/////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = 0;
    }
    friend class linkedQueue;
};

class linkedQueue {
private:
    Node* front;
    Node* rear;
    bool visited[10] = {false};
    int size;
    int graph[10][10];

public:
    linkedQueue() { front = 0; rear = 0; }
    ~linkedQueue();
    void buildQueue(int data[][10], int);
    void enqueue(int);
    int dequeue();
    bool isEmpty();
    void bfs(int);
    void print_graph();
};

linkedQueue::~linkedQueue() {
    Node* p;
    while (front != 0) {
        p = front;
        front = front->next;
        delete p;
    }
}

void linkedQueue::buildQueue(int data[][10], int num) {
    size = num;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            graph[i][j] = data[i][j];
        }
    }
}

void linkedQueue::enqueue(int data) {
    Node* temp = new Node(data);
    if (front == 0) {
        front = temp;
        rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

int linkedQueue::dequeue() {
    Node* p;
    int num;
    num = front->data;
    p = front;
    if (front == rear) {
        front = 0;
        rear = 0;
    }
    else
        front = front->next;
    delete p;
    return num;
}

bool linkedQueue::isEmpty() {
    if (front == 0)
        return true;
    else
        return false;
}

void linkedQueue::bfs(int v=0) {
    int j;
    visited[v] = true;
    enqueue(v);

    while (!isEmpty()) {
        v = dequeue();
        cout << v << "  ";

        for (j=0; j<size; j++) {
            if(graph[v][j] && !visited[j]) {
                visited[j] = true;
                enqueue(j);
            }
        }
    }
}

void linkedQueue::print_graph() {
    cout << "   ";
    for(int i=0; i<size; i++) {
        cout << "v" << i << " ";
    } cout << endl;
    for(int i=0; i<size; i++) {
        cout << "v" << i << "  ";
        for(int j=0; j<size; j++) {
            cout << graph[i][j] << "  ";
        } cout << endl;
    }
}

int main() {
    int graph1[10][10] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 1, 1} };

    linkedQueue Q1;
    Q1.buildQueue(graph1, 8);
    cout << "*******    Adjacency Matrix    *******" << endl << endl;
    Q1.print_graph(); cout << endl;
    cout << "  Breadth first search result -> ";
    Q1.bfs(0); cout << endl << endl << endl;

    int graph2[10][10] ={
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 0} };

    linkedQueue Q2;
    Q2.buildQueue(graph2, 7);
    cout << "*******    Adjacency Matrix    *******" << endl << endl;
    Q2.print_graph(); cout << endl;
    cout << "  Breadth first search result -> ";
    Q2.bfs(0);

    return 0;
}