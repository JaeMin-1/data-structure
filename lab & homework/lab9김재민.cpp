////////////////////////////////////////////////////////////////////////
// Lab9 : MAX HEAP implementation & HEAP SORT
// Name: 김재민
// ID: 20181592
/////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
	int heap[11] = { 0, 26, 5, 77, 1, 61, 11, 59, 15, 48, 19 };
	int n = 10;              
	int MaxSize = 11;        
	int level = 0;

public:
	bool HeapFull();
	bool HeapEmpty();
	void Print();
	void Search(int item);
	void Level();
	void adjust(int heap[], int i, int n);
	void MakeHeap();
	void HeapSort();
	void Delete();
	void Insert(int item);
};

bool MaxHeap::HeapFull() {
	if (n == MaxSize) return true;
	else return false;
}

bool MaxHeap::HeapEmpty() {
	if (n == 0) return true;
	else return false;
}

void MaxHeap::Print() {
	cout << "Heap :  ";
	for (int i = 1; i <=n; i++) {           //실수로 10이라고 해놓은것을 n으로 수정했습니다.
		cout << heap[i] << " ";
	} cout << endl;
}

void MaxHeap::Search(int item) {
	if (!HeapEmpty()) {
		for (int i = 1; i <= n; i++) {
			if (item == heap[i]) {
				cout << item << " is found" << endl; break;
			}
			if (i == n) {
				cout << "not found" << endl;
			}
		}
	}
}

void MaxHeap::Level() {
	int heapsize = n;
	while (heapsize != 0) { heapsize = heapsize / 2; level++; }
	cout << "Level of Heap is " << level << endl;
}

void MaxHeap::adjust(int heap[], int i, int n) {
	int child;
	child = 2 * i;
	int temp = heap[i];
	while (n >= child) {
		if (n > child && heap[child] < heap[child + 1])
			child = child + 1;

		if (temp >= heap[child])
			break;
		heap[child / 2] = heap[child];
		child = 2 * child;
	}
	heap[child / 2] = temp;
	return;
}

void MaxHeap::MakeHeap() {
	for (int i = n / 2; i > 0; i--) adjust(heap, i, n);
}

void MaxHeap::HeapSort() {
	for(int i=n-1; i>0; i--) {
		swap(heap[1], heap[i + 1]);
		adjust(heap, 1, i);
	}
}

void MaxHeap::Delete() {
	int parent, child;
	int item, temp;

	item = heap[1];
	temp = heap[n--];
	parent = 1;
	child = 2;
	while (child <= n) {
		if ((child <= n) && (heap[child] < heap[child + 1]))
			child++;
		if (temp >= heap[child]) break;
		heap[parent] = heap[child];
		parent = child;
		child = child * 2;
	}
	heap[parent] = temp;
}

void MaxHeap::Insert(int item) {
	int i;
	if (HeapFull()) {
		cout << "Heap is full..." << endl; return;
	}
	i = ++(n);
	while ((i != 1) && (item > heap[i / 2])) {
		heap[i] = heap[i / 2];
		i = i / 2;
	}
	heap[i] = item;
}

int main() {
	MaxHeap Heap;

	int num = 0;
	int number = 0;
	while (num != 8) {
		cout << "Enter Command : (1.print 2.search 3.leveltest 4.makeheap 5.heapsort 6.delete, 7.insert 8.quit) ";
		cin >> num;
		if (num == 1) Heap.Print();
		else if (num == 2) {
			cout << "Enter a number to search : ";
			cin >> number;
			Heap.Search(number);
		}
		else if (num == 3) Heap.Level();
		else if (num == 4) {
			Heap.MakeHeap();
			cout << "Heap 변환 : ";
			Heap.Print();
		}
		else if (num == 5) {
			Heap.HeapSort();
			cout << "Heap 변환 : ";
			Heap.Print();
		}
		else if (num == 6) {
			Heap.Delete();
			Heap.Print();
		}
		else if (num == 7) {
			cout << "Enter a number to search : ";
			cin >> number;
			Heap.Insert(number);
			Heap.Print();
		}
		else if (num == 8) break;
	}
	return 0;
}