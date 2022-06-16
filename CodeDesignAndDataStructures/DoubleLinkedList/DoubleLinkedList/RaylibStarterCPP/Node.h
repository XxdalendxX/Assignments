#pragma

class Node
{
public:

	Node();
	Node(int value, Node* next, Node* Previous);
	~Node();

public:

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

protected:

	

public:

	Node* head;
	Node* tail;
	
	int _value;

	Node* next;
	Node* previous;

	int tailVal;
	int headVal;
	int nodeTot;

};