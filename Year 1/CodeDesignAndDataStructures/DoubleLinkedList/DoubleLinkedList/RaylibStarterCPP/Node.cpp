#include"Node.h"


Node::Node()
{
	
}
Node::Node(int Value, Node* Next, Node* Previous)
{
	_value = Value;
	next = Next;
	previous = Previous;
}
Node::~Node()
{

}