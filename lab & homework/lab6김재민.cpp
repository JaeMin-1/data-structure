////////////////////////////////////////////////////////////////////////
// Lab6 : Singly Linked List
// Name : ±èÀç¹Î
// ID : 20181592
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;

class Node {
private:
	int data;
	Node* next;
	Node(int value) { data = value; next = 0; }
	friend class List;
};

class List {
private:
	Node* head;

public:
	List() { head = 0; }
	void insert(int);
	void deleteN(int);
	void search(int);
	void findMax();
	void quit();
	void displayList();
};

void List::insert(int data) {
	Node* temp = new Node(data);
	Node* p, * q = NULL;

	if (head == 0) head = temp;
	else if (temp->data < head->data) {
		temp->next = head; head = temp;
	}
	else {
		p = head;
		while ((p != 0) && (p->data < temp->data)) {
			q = p; p = p->next;
		}
		if (p != 0) { temp->next = p; q->next = temp; }
		else q->next = temp;
	}
}

void List::deleteN(int data) {
	Node* p, * q = head;

	if (head->data == data) {
		p = head;
		head = head->next;
		delete p;
	}
	else {
		p = head;
		while (p != 0 && p->data != data) {
			q = p;
			p = p->next;
		}
		if (p != 0) {
			q->next = p->next;
			delete p;
		}
		else cout << data << " is not in the list" << endl;
	}
}

void List::search(int data) {
	Node* p = head;

	if (head != 0) {
		while (p != 0 && p->data != data) {
			p = p->next;
		}
		if (p) cout << p->data << " is found." << endl;
		else cout << data << " is not in the list." << endl;
	}
	else cout << "List is empty!" << endl;
}

void List::findMax() {
	Node* p = head;
	Node* max = head;
	while (p->next != NULL) {
		p = p->next;
		if (max->data < p->data) max = max->next;
	}
	cout << max->data << " is the max-number" << endl;
}

void List::quit() {
	Node* p;
	while (head != 0) {
		p = head;
		head = head->next;
		delete p;
	}
}

void List::displayList() {
	Node* p;
	if (head == 0) cout << "List is empty!\n";
	else {
		p = head;
		cout << "--- List ---\n";
		for (int i = 1; p != 0; i++) {
			cout << setw(5) << i << " : " << p->data << endl;
			p = p->next;
		}
	}
}

int main() {
	int num = 0; int number;
	List l1;
	while (true) {
		cout << "Command : 1)insert, 2)delete, 3)search, 4)findMax 5)quit => ";
		cin >> num;
		if (num == 1) {
			cout << "Input a number => ";
			cin >> number;
			l1.insert(number);
			l1.displayList();
		}
		else if (num == 2) {
			cout << "Input a number => ";
			cin >> number;
			l1.deleteN(number);
			l1.displayList();
		}
		else if (num == 3) {
			cout << "Input a number => ";
			cin >> number;
			l1.search(number);
			l1.displayList();
		}
		else if (num == 4) {
			l1.findMax();
			l1.displayList();
		}
		else if (num == 5) {
			l1.quit();
			l1.displayList();
			break;
		}
	}
	return 0;
}