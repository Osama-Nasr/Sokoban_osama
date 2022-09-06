#pragma once
#include <iostream>
#include <fstream>
#define POSITION_BEG 0
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
	Node* head;

	int numberOfInsertions = 0;
public:
	bool changedFirst = false;
	LinkedList();
	LinkedList(int A[], int n);
	~LinkedList();
	void Display();
	int Length();

	void Insert(int index, long long int num, long double FT, int lvl);
	void Insert(int index, long long int num, long double FT, int lvl, int flage);
	void Insert(int index, long long int num, long double FT, int lvl, Node* head);
	void Insert(int index, long long int num, long double FT, int lvl, Node* head, int& numOfInsertions);
	void Insert(int index, long long int num, long double FT, int lvl, int& numOfInsertions, int flage);

	int Delete(int index);

	void changeFirst(long long int num, long double FT, int lvl, Node* head, bool& CF, int& numOfInsertion);		//for the nodes
	void changeFirst(long long int num, long double FT, int lvl, Node* head);
	void changeFirst(long long int num, long double FT, int lvl);
	
	int getNumberOfInsertions();
	int* getNumberOfInsertions(int flage);
	void setNumberOfInsertions(int n);
	void incrementNumberOfInsertions();
	
	bool* getChangedFirst(int flage);
	bool getChangedFirst();
	void setChangedFirst(bool x);
	void setChangedFirst(bool& CF, bool set);

	Node* getHead();

	void clear();

	void writeToFile();
	void writeToFile(int lvl, long long int move, long double finishTime);
	void readFromFile();
	
};