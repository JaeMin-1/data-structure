////////////////////////////////////////////////////////////////////////
// Lab7 : Linked Stack & Queue
// Name : ±Ë¿ÁπŒ
// ID : 20181592
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
class Node
{
private:
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = 0;
    }
    friend class linkedStack;
    friend class linkedQueue;
    friend class linkedList;
};

class linkedStack
{
private:
    Node* head;

public:
    linkedStack() { head = 0; }
    ~linkedStack();
    void createStack();
    void push(int);
    int pop();
    int isEmpty();
    void displayStack();
};

class linkedQueue
{
private:
    Node* front;
    Node* rear;

public:
    linkedQueue()
    {
        front = 0;
        rear = 0;
    }
    ~linkedQueue();
    void createQueue();
    void enqueue(int);
    int dequeue();
    int isEmpty();
    void displayQueue();
    void searchQueue(int);
};

class linkedList
{
private:
    Node* head;

public:
    linkedList() { head = 0; }
    ~linkedList() {};
    void insert(int);
    int is_empty();
    void display();
};

void linkedList::insert(int data)
{
    Node* temp = new Node(data);
    Node* p, * q = 0;

    if (head == 0)
        head = temp;
    else if (temp->data < head->data || temp->data == head->data)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        p = head;
        while ((p != 0) && (p->data < temp->data))
        {
            q = p;
            p = p->next;
        }
        if (p != 0)
        {
            temp->next = p;
            q->next = temp;
        }
        else
            q->next = temp;
    }
}

int linkedList::is_empty()
{
    if (head == 0)
        return 1;
    else
        return 0;
}

void linkedList::display()
{
    Node* p;
    if (!is_empty())
    {
        cout << "List: "
            << "   ";
        p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
        cout << "List is empty!\n";
}

//Queue
linkedQueue::~linkedQueue()
{
    Node* p;
    while (front != 0)
    {
        p = front;
        front = front->next;
        delete p;
    }
}
void linkedQueue::createQueue()
{
    front = 0;
    rear = 0;
}

void linkedQueue::enqueue(int data)
{
    Node* temp = new Node(data);
    if (front == 0)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int linkedQueue::dequeue()
{
    Node* p;
    int num;
    num = front->data;
    p = front;
    if (front == rear)
    {
        front = 0;
        rear = 0;
    }
    else
        front = front->next;
    delete p;
    return num;
}

int linkedQueue::isEmpty()
{
    if (front == 0)
        return 1;
    else
        return 0;
}

void linkedQueue::displayQueue()
{
    Node* p;
    if (!isEmpty())
    {
        p = front;
        cout << "Queue : ";
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
        cout << "Queue is empty!\n";
}

// LinkedStack

linkedStack::~linkedStack()
{
    Node* p;
    while (head != 0)
    {
        p = head;
        head = head->next;
        delete p;
    }
}
void linkedStack::createStack()
{
    head = 0;
}

void linkedStack::push(int data)
{
    Node* temp = new Node(data);
    if (head == 0)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
}

int linkedStack::pop()
{
    Node* p;
    int num;
    num = head->data;
    p = head;
    head = head->next;
    delete p;
    return num;
}

int linkedStack::isEmpty()
{
    if (head == 0)
        return 1;
    else
        return 0;
}

void linkedStack::displayStack()
{
    Node* p;
    if (!isEmpty())
    {
        cout << "Stack\n";
        p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
        cout << "Stack is empty!\n";
}

int main()
{
    linkedStack s1;
    linkedQueue s2;
    linkedList s3;
    int num;
    int command = 1;
    while (command != 6)
    {
        cout << "Command : 1.push, 2.pop, 3.enqueue, 4.dequeue, 5.Makelist 6.quit = > ";
        cin >> command;
        if (command == 1)
        {
            cout << "Input a number => ";
            cin >> num;
            s1.push(num);
            s1.displayStack();
        }
        else if (command == 2)
        {
            if (!s1.isEmpty())
            {
                num = s1.pop();
                cout << num << " has been popped " << endl;
                s1.displayStack();
            }
            else
                cout << "Stack is empty!\n";
        }
        else if (command == 3)
        {
            cout << "Enter a number => ";
            cin >> num;
            s2.enqueue(num);
            s2.displayQueue();
        }
        else if (command == 4)
        {
            if (!s2.isEmpty())
            {
                num = s2.dequeue();
                cout << num << " has been popped " << endl;
                s2.displayQueue();
            }
            else
                cout << "Queue is empty!\n";
        }

        else if (command == 5)
        {
            while (!s1.isEmpty())
            {
                num = s1.pop();
                s3.insert(num);
            }
            while (!s2.isEmpty())
            {
                num = s2.dequeue();
                s3.insert(num);
            }
            s3.display();
        }

        else if (command == 6)
            break;
        else
            cout << "Bad command" << endl;
    }
    return 0;
}