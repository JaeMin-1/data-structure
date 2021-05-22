#include <iostream>
#include <string>
using namespace std;

struct student {
	string name;
	int age;
	string major;
};

struct Point { int x; int y; };

struct employee {
	string name;
	int emp_number;
};
struct company {
	string locate;
	int revenue;
	employee emp1;
};

int main() {
	student st1;
	st1.name = "Kim"; st1.age = 26; st1.major = "computer";
	student st2 = { "Lee", 25, "mathematics" };
	cout << "Name : " << st1.name << endl;
	cout << st2.name;

	Point p1 = {1,0};
	p1.x = 10;
	p1.y = 20;
	cout << p1.x << " " << p1.y << endl;

	Point p[5];
	for (int i = 0; i < 5; i++) {
		p[i].x = i; p[i].y = i;
		cout << p[i].x << " " << p[i].y << endl;
	}

	company mycom = { "seoul", 1000, {"kim", 0001} };
	cout << mycom.locate << endl;
	cout << mycom.revenue << endl;
	cout << mycom.emp1.name << " ";
	cout << mycom.emp1.emp_number;

	return 0;
}