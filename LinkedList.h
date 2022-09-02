#pragma once
#include <iostream>
using namespace std;

class Node {
public:
	Node* prev;
	long long int move;
	long double finishTime;
	int lvl;
	Node* next;
};

class LinkedList {
private:
	Node* head;
//	Node* tail;

	bool changedFirst = false;
	int numberOfInsertions = 0;
public:
	LinkedList();
	LinkedList(int A[], int n);
	~LinkedList();
	void Display();
	int Length();
	void Insert(int index, long long int num, long double FT, int lvl);
	int Delete(int index);
	void changeFirst(long long int num, long double FT, int lvl);		//for the nodes
	int getNumberOfInsertions();
	bool getChangedFirst();

};