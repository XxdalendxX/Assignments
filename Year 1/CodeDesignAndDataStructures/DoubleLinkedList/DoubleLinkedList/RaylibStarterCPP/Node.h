#pragma

class Node
{
public:

	Node();
	Node(int value, Node* next, Node* Previous);
	~Node();
public:
	
	int _value;

	Node* next;
	Node* previous;
};