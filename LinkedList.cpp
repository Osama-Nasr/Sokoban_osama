#include "LinkedList.h"

LinkedList::LinkedList() {
	head = new Node;
	head->move = 0;
	head->finishTime = 0;
	head->lvl = 0;
	head->next = nullptr;
	setNumberOfInsertions(0);
	setChangedFirst(false);
}

LinkedList::LinkedList(int* A, int n) {

	head = new Node;
	head->move = A[0];
	head->next = nullptr;
	Node* tail = head;

	for (int i = 1; i < n; i++) {
		Node* t = new Node;
		t->move = A[i];
		t->next = tail->next; // tail->next is pointing to NULL
		tail->next = t;
		tail = t;
	}
}

LinkedList::~LinkedList() {
	/*Node* p = head;

	while (head) {
		head = head->next;
		delete p;
		p = head;
	}*/
}

Node* LinkedList::getHead()
{
	return this->head;
}

void LinkedList::clear() {
	
	Node* p = head;

	while (head) {
		head = head->next;
		delete p;
		p = head;
	}
}

void LinkedList::writeToFile()
{
	fstream rs;
	rs.open("results/result.txt", fstream::app);
	if (rs.fail())
	{
		cerr << "Error while opening the file results/result";
	}

	Node* p = head;

	while (p != nullptr && p->move >= 0) {		//check as well if the number is integer as if it was nigitive it means that it is empty
		rs << p->lvl << " " << p->move << " " << p->finishTime << endl;
		p = p->next;
	}
}

void LinkedList::writeToFile(int lvl, long long int move, long double finishTime)
{
	fstream rs;
	rs.open("results/result.txt", fstream::app);
	if (rs.fail())
	{
		cerr << "Error while opening the file results/result";
	}
		rs << lvl << " " << move << " " << finishTime << endl;
}

void LinkedList::readFromFile()
{
	int lvl = 0;
	long long int moves = 0;
	long double FT = 0.0;
	ifstream rs;
	rs.open("results/result.txt");

	//Insert(POSITION_BEG, moves, FT, lvl);
	while (rs >> lvl >> moves >> FT)
	{
		
	}
	if (rs.fail())
		cerr << "Error in opening a file";
}

void LinkedList::Display() {
	Node* p = this->head;
	if (this->changedFirst ==  false)
	{
		cout << "CF=false" << endl;
	}
	else {
		while (p != nullptr) {		//check as well if the number is integer as if it was nigitive it means that it is empty
			cout << p->lvl << " " << p->move << " " << p->finishTime << endl;
			p = p->next;
		}
	}
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

void LinkedList::Insert(int index, long long int num, long double FT, int lvl, Node* head) {

	numberOfInsertions++;
	if (index < 0 || index > numberOfInsertions) {
		return;
	}

	Node* p = head;
	Node* t = new Node;
	t->move = num;
	t->lvl = lvl;
	t->finishTime = FT;


	if (index == 0) {
		t->next = head;
		head = t;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		t->next = p->next;

		p->next = t;
	}
}

void LinkedList::Insert(int index, long long int num, long double FT, int lvl) {

	numberOfInsertions++;
	if (index < 0 || index > numberOfInsertions) {
		return;
	}

	Node* p = this->head;
	Node* t = new Node;
	t->move = num;
	t->lvl = lvl;
	t->finishTime = FT;


	if (index == 0) {
		t->next = head;
		head = t;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		t->next = p->next;

		p->next = t;
	}
}

void LinkedList::Insert(int index, long long int num, long double FT, int lvl, int flage) {

	incrementNumberOfInsertions();
	if (index < 0 || index > this->numberOfInsertions) {
		return;
	}

	Node* p = this->head;
	Node* t = new Node;
	t->move = num;
	t->lvl = lvl;
	t->finishTime = FT;


	if (index == 0) {
		t->next = head;
		head = t;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		t->next = p->next;

		p->next = t;
	}
}

void LinkedList::Insert(int index, long long int num, long double FT, int lvl, Node* head, int& numOfInsertions) {

	numOfInsertions = numOfInsertions + 1;
	if (index < 0 || index > numOfInsertions) {
		return;
	}

	Node* p = head;
	Node* t = new Node;
	t->move = num;
	t->lvl = lvl;
	t->finishTime = FT;


	if (index == 0) {
		t->next = head;
		head = t;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		t->next = p->next;

		p->next = t;
	}
}

void LinkedList::Insert(int index, long long int num, long double FT, int lvl, int& numOfInsertions, int flage) {

	numOfInsertions = numOfInsertions + 1;
	if (index < 0 || index > numOfInsertions) {
		return;
	}

	Node* p = this->head;
	Node* t = new Node;
	t->move = num;
	t->lvl = lvl;
	t->finishTime = FT;


	if (index == 0) {
		t->next = head;
		head = t;
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		t->next = p->next;

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
	
			x = p->move;
			delete p;
		}
	}
	else {
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}
		x = p->move;
		delete p;
	}
	return x;
}

void LinkedList::changeFirst(long long int num, long double FT, int lvl, Node* head, bool& CF, int& numOfInsertion)
{
	Node* p = head;
	p->move = num;
	p->finishTime = FT;
	p->lvl = lvl;
	CF = true;
	numOfInsertion = numOfInsertion + 1;

	//setChangedFirst(true);		//doesn't work
	//changedFirst = true;			//doesn't work
	//this->numberOfInsertions++;   //doesn't work
	//numberOfInsertions++;		    //doesn't work
}

void LinkedList::changeFirst(long long int num, long double FT, int lvl, Node* head)
{
	Node* p = head;
	p->move = num;
	p->finishTime = FT;
	p->lvl = lvl;
	//CF = false;
	setChangedFirst(true);
	//changedFirst = true;
	numberOfInsertions++;
}

void LinkedList::changeFirst(long long int num, long double FT, int lvl)
{
	Node* p = this->head;
	p->move = num;
	p->finishTime = FT;
	p->lvl = lvl;
	//CF = false;
	setChangedFirst(true);
	//changedFirst = true;
	numberOfInsertions++;
}

int LinkedList::getNumberOfInsertions()
{
	return numberOfInsertions;
}

int* LinkedList::getNumberOfInsertions(int flage)
{
	return &numberOfInsertions;
}

void LinkedList::setNumberOfInsertions(int n)
{
	this->numberOfInsertions = n;
}

void LinkedList::incrementNumberOfInsertions()
{
	this->numberOfInsertions++;
}

bool LinkedList::getChangedFirst()
{
	return changedFirst;
}

bool* LinkedList::getChangedFirst(int flage)
{
	return &changedFirst;
}

void LinkedList::setChangedFirst(bool x)
{
	this->changedFirst = x;
}

void LinkedList::setChangedFirst(bool &CF, bool set)
{
	CF = set;
}
