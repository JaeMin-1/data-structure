////////////////////////////////////////////////////////////////////////
// Lab11 : Hashing
// Name : 김재민
// ID : 20181592
/////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
#define MaxSize 7
int Hash(int key) { return key % MaxSize; }

class Node {
private:
    int data;
    Node* link;
    Node(int value) { data = value; link = 0; }
    friend class Htable;
};

class Htable {
private:
    Node* head;
    Node* HT[MaxSize] = { NULL };
public:
    Htable() { head = 0; }
    int findkey(int);
    int insertkey(int);
    int deletekey(int);
    void printable();
};

int Htable::findkey(int key) {
    int index = Hash(key);
    Node* p = HT[index];

    if (p == NULL) return false;
    else {
        Node* q = p;
        while ((q != NULL) && (q->data != key)) q = q->link;
        if (q == NULL) return false;
        else return true;
    }
}

int Htable::insertkey(int key) {
    int index = Hash(key);
    int check = findkey(key);

    if (check == true) return false;
    Node* q = new Node(key);

    if (HT[index] == NULL) HT[index] = q;
    else {
        Node* p = HT[index];
        while (p->link != NULL) p = p->link;
        p->link = q;
    }
}

void Htable::printable() {
    for (int i = 0; i < MaxSize; i++) {
        cout << "HashT[" << i << "] -> ";
        Node* p = HT[i];
        for (p; p!=NULL; p=p->link) cout << p->data << " ";
        cout << endl;
    }
}

int Htable::deletekey(int key) {
    Node* p, * q = head;
    int check = findkey(key);
    if (check == false) return false;
    else {
        int index = Hash(key);
        head = HT[index];
        
        if (head->data == key) {
            p = head;
            head = head->link;
            delete p;
        }
        else {
            p = head;
            while (p != 0 && p->data != key) {
                q = p;
                p = p->link;
            }
            if (p != 0) {
                q->link = p->link;
                delete p;
            }
        }
    }
}

int main() {
    Htable ht;
    int num = 0; int key;
    while (true) {
        cout << "Enter command(1.insert  2.find  3.delete  4.quit) : ";
        cin >> num;
        if (num == 1) {
            cout << "Enter Key => ";
            cin >> key;
            ht.insertkey(key);
            ht.printable();
        }
        else if (num == 2) {
            cout << "Enter Key => ";
            cin >> key;
            if (ht.findkey(key)) cout << "Found" << endl;
            else cout << "Not Found" << endl;
            ht.printable();
        }
        else if (num == 3) {
            cout << "Enter Key => ";
            cin >> key;
            ht.deletekey(key);
            ht.printable();
        }
        else if (num == 4) break;
        else cout << "This is Wrong Number" << endl;
    }

    return 0;
}