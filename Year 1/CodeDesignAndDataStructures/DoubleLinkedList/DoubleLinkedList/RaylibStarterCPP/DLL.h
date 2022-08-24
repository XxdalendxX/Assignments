#pragma once

class Node;

class DLL //Double Linked List
{
public:
	Node* head;
	Node* tail;

	int tailVal;
	int headVal;
	int nodeTot;

	DLL();
	~DLL();

	void InsertHeadNode(int value);
	void DeleteHeadNode();
	void InsertTailNode(int value);
	void DeleteTailNode();
	void InsertArbitraryNode(int position, int value);
	void DeleteArbitraryNode(int position);

	int NodeCount();
	Node* NodeFind(int position);
	bool NodeCheck();

	int ReturnHeadValue();
	int ReturnTailValue();

	void ListSort();
};