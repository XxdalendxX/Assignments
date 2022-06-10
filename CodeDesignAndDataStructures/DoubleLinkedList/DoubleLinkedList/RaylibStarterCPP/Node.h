

class Node
{
public:

	Node();
	Node(int value, Node* next, Node* Previous);
	~Node();

private:

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

	Node* head;
	Node* tail;

public:

	int value;

	Node* next;
	Node* previous;

};