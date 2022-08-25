#pragma once

class Node;

class DLL //Double Linked List
{
public:
	Node* head;
	Node* tail;

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
	bool IsEmpty();

	int ReturnHeadValue();
	int ReturnTailValue();

	void ListSort();
};