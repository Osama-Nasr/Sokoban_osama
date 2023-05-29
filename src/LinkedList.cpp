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

void LinkedList::writeToFile(int lvl, long long int move, long double finishTime)
{
	fstream rs;
	rs.open("results/result.txt", fstream::app);
	if (rs.fail())
	{
		cerr << "Error while opening the file results/result";
	}
		rs << lvl << " " << move << " " << finishTime << endl;
	rs.close();
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

int LinkedList::Delete(int index) {
	int x = -1;
	Node* p = head;

	if (index < 0 || index > Length()) {
		return x;
	}

	if (index == 1) {
		if (Length() == 1)
		{
			head->move = -1;		
			head->finishTime = -1;	
			head->lvl = -1;			
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

void LinkedList::MergeSort(Node*& hd, int typeSort)
{
	Node* head = hd;
	Node* a;
	Node* b;

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, a, b);

	/* Recursively sort the sublists */
	MergeSort(a, typeSort);
	MergeSort(b, typeSort);

	/* answer = merge the two sorted lists together */
	//*headRef = SortedMerge(a, b);
	hd = SortedMerge(a, b, typeSort);
}
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
Node* LinkedList::SortedMerge(Node* a, Node* b, int typeSort)
{
	Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if (typeSort == MOVES)
	{
		if (a->move <= b->move) {
			result = a;
			result->next = SortedMerge(a->next, b, typeSort);
		}
		else {
			result = b;
			result->next = SortedMerge(a, b->next, typeSort);
		}
		return (result);
	}
	else if (typeSort == FINISH_TIME)
	{
		if (a->finishTime <= b->finishTime) {
			result = a;
			result->next = SortedMerge(a->next, b, typeSort);
		}
		else {
			result = b;
			result->next = SortedMerge(a, b->next, typeSort);
		}
		return (result);
	}
}

void LinkedList::FrontBackSplit(Node* source, Node*& frontRef, Node*& backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	frontRef = source;
	backRef = slow->next;
	slow->next = NULL;
}

void LinkedList::sortedInsert(Node*& head_ref, int typeSort, long long int move, long double FT, int lvl)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->move = move;
	new_node->finishTime = FT;
	new_node->lvl = lvl;
	new_node->next = NULL;

	Node* current;
	/* Special case for the head end */
	if (typeSort == MOVES)
	{
		if (head_ref == NULL || head_ref->move >= new_node->move) {
			new_node->next = head_ref;
			head_ref = new_node;
		}
		else {
			/* Locate the node before the
	 point of insertion */
			current = head_ref;
			while (current->next != NULL && current->next->move < new_node->move) {
				current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
		}
	}
	else if (typeSort == FINISH_TIME)
	{
		if (head_ref == NULL
			|| head_ref->finishTime
			>= new_node->finishTime) {
			new_node->next = head_ref;
			head_ref = new_node;
		}
		else {
			/* Locate the node before the
	 point of insertion */
			current = head_ref;
			while (current->next != NULL
				&& current->next->finishTime
				< new_node->finishTime) {
				current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
		}
	}
	this->numberOfInsertions++;
}

int LinkedList::getNumberOfInsertions()
{
	return numberOfInsertions;
}

void LinkedList::setNumberOfInsertions(int n)
{
	this->numberOfInsertions = n;
}

bool LinkedList::getChangedFirst()
{
	return changedFirst;
}

void LinkedList::setChangedFirst(bool x)
{
	this->changedFirst = x;
}

