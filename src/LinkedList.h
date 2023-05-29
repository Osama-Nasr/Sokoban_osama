#pragma once
#include <iostream>
#include <fstream>
#define POSITION_BEG 0
#define MOVES 1
#define FINISH_TIME 2

using namespace std;

class Node {
public:
	long long int move;
	long double finishTime;
	int lvl;
	Node* next;
};

class LinkedList {
private:

	int numberOfInsertions = 0;
public:
	Node* head;
	bool changedFirst = false;
	LinkedList();
	~LinkedList();
	void Display();
	int Length();

	void Insert(int index, long long int num, long double FT, int lvl);
	void sortedInsert(Node*& head_ref, int typeSort, long long int move, long double FT, int lvl);

	int Delete(int index);

	void changeFirst(long long int num, long double FT, int lvl);
	
	int getNumberOfInsertions();
	void setNumberOfInsertions(int n);
	
	bool getChangedFirst();
	void setChangedFirst(bool x);

	Node* getHead();

	void clear();

	void writeToFile(int lvl, long long int move, long double finishTime);

	void MergeSort(Node*& hd, int typeSort);
	Node* SortedMerge(Node* a, Node* b, int typeSort);
	void FrontBackSplit(Node* source, Node*& frontRef, Node*& backRef);
};