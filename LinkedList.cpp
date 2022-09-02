#include "LinkedList.h"

LinkedList::LinkedList() {
	head = new Node;
	head->prev = nullptr;
	head->move = 0;
	head->finishTime = 0;
	head->lvl = 0;
	head->next = nullptr;
}

LinkedList::LinkedList(int* A, int n) {

	head = new Node;
	head->prev = nullptr;
	head->move = A[0];
	head->next = nullptr;
	Node* tail = head;

	for (int i = 1; i < n; i++) {
		Node* t = new Node;
		t->prev = tail;
		t->move = A[i];
		t->next = tail->next; // tail->next is pointing to NULL
		tail->next = t;
		tail = t;
	}
}

LinkedList::~LinkedList() {
	Node* p = head;

	while (head) {
		head = head->next;
		delete p;
		p = head;
	}
}

void LinkedList::Display() {
	Node* p = head;
	int n = 1;
	for (int i = 0; i < Length(); i++)
		cout << i + 1 << " ";

	cout << endl;
	while (p != nullptr && p->move >= 0) {		//check as well if the number is integer as if it was nigitive it means that it is empty
		cout << p->move << flush;
		cout << p->finishTime << flush;
		p = p->next;
		if (p != nullptr) {
			cout << " " << flush;
		}
		++n;
		if (n > 10)
			cout << " ";
	}
	cout << endl;
}

int LinkedList::Length() {
	int length = 0;
	Node* p = head;
	while (p != nullptr) {
		if (p->move >= 0)
		{
			length++;
			p = p->next;
		}
		else
			break;
	}
	return length;
}

void LinkedList::Insert(int index, long long int num, long double FT, int lvl) {

	numberOfInsertions++;
	if (index < 0 || index > numberOfInsertions) {
		return;
	}

	Node* p = head;
	Node* t = new Node;
	t->move = num;
	t->move = lvl;
	t->finishTime = FT;


	if (index == 0) {
		t->prev = nullptr;
		t->next = head;
		head->prev = t;
		head = t;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		t->prev = p;
		t->next = p->next;
		if (p->next) {
			p->next->prev = t;
		}
		p->next = t;
	}
}

int LinkedList::Delete(int index) {
	int x = -1;
	Node* p = head;

	if (index < 0 || index > Length()) {
		return x;
	}

	if (index == 1) {
		if (Length() == 1)
		{
			head->move = -1;			//that means that the node it empty
			head->finishTime = -1;			//that means that the node it empty
			head->lvl = -1;			//that means that the node it empty
			changedFirst = false;		//so if it was laster on needed to insert we will just change it (flage)
		}
		else {
			head = head->next;
			if (head) {
				head->prev = nullptr;
			}
			x = p->move;
			delete p;
		}
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		p->prev->next = p->next;
		if (p->next) {
			p->next->prev = p->prev;
		}
		x = p->move;
		delete p;
	}
	return x;
}

void LinkedList::changeFirst(long long int num, long double FT, int lvl)
{
	Node* p = head;
	p->move = num;
	p->finishTime = FT;
	p->lvl = lvl;
	changedFirst = true;
	numberOfInsertions++;
}

int LinkedList::getNumberOfInsertions()
{
	return numberOfInsertions;
}

bool LinkedList::getChangedFirst()
{
	return changedFirst;
}
