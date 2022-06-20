#include"Node.h"


Node::Node()
{
	head = new Node(0, nullptr, nullptr);
	tail = new Node(0, nullptr, head);
	head->next = tail;
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
////////////////////////////////////////////////////////////////////////////////////////////
//Deletes or inserts nodes either at the head, tail or an assigned point in the list
////////////////////////////////////////////////////////////////////////////////////////////
void Node::InsertHeadNode(int value)
{
	Node* newNode = new Node(value, head->next, head);
	head->next->previous = newNode;
	head->next = newNode;
}

void Node::InsertTailNode(int value)
{
	Node* newNode = new Node(value, tail, tail->previous);
	tail->previous->next = newNode;
	tail->previous = newNode;
}

void Node::DeleteHeadNode()
{
	Node* node = head->next;
	if (node->next == nullptr)
	{
		return;
	}
	node->next->previous = node->previous;
	node->previous->next = node->next;
	delete node;
}

void Node::DeleteTailNode()
{
	Node* node = tail->previous;
	if (node->previous == nullptr)
	{
		return;
	}
	node->next->previous = node->previous;
	node->previous->next = node->next;
	delete node;
}

void Node::InsertArbitraryNode(int position, int value)
{
	if (NodeCount() < position)
	{
		return;
	}
	Node* insertPos = NodeFind(position);

	Node* newNode = new Node(value, insertPos->next, insertPos);
	insertPos->next = newNode;
}

void Node::DeleteArbitraryNode(int position)
{
	if (NodeCount() < position)
	{
		return;
	}
	Node* nodePos = NodeFind(position + 1);
	if (nodePos->previous == nullptr || nodePos->next == nullptr)
	{
		return;
	}

	nodePos->next->previous = nodePos->previous;
	nodePos->previous->next = nodePos->next;
	delete nodePos;
}
////////////////////////////////////////////////////////////////////////////////////////////
//Counts total nodes, finds specific node for use, and checks if list is empty, 
////////////////////////////////////////////////////////////////////////////////////////////
int Node::NodeCount()
{
	int count = 0;
	Node* currentNode = head;
	while (currentNode->next->next != nullptr)
	{
		if (currentNode->next != nullptr)
		{
			count++;
		}
		currentNode = currentNode->next;
	}

	return count;
}

Node* Node::NodeFind(int position)
{
	int count = 0;
	Node* currentNode = head;
	while (count != position)
	{
		count++;
		currentNode = currentNode->next;
	}

	return currentNode;
}

bool Node::NodeCheck()
{
	if (head->next != tail)
	{
		return true;
	}
	return false;
}
////////////////////////////////////////////////////////////////////////////////////////////
//Returns current head and tail values in the list. 
////////////////////////////////////////////////////////////////////////////////////////////
int Node::ReturnHeadValue()
{
	return head->next->_value;
}

int Node::ReturnTailValue()
{
	return tail->previous->_value;
}
////////////////////////////////////////////////////////////////////////////////////////////
//Sorts the list in ascending order
////////////////////////////////////////////////////////////////////////////////////////////
void Node::ListSort()
{
	Node* currentNode = head->next;
	bool swapped = true;
	while (swapped == true)
	{
		bool swap = false;
		while (currentNode->next->next != nullptr)
		{
			if (currentNode->_value > currentNode->next->_value)
			{
				swap = true;
				int temp = currentNode->_value;
				currentNode->_value = currentNode->next->_value;
				currentNode->next->_value = temp;
			}
			currentNode = currentNode->next;
		}

		if (swap == false)
		{
			swapped = false;
		}
		swap = false;

		currentNode = head->next;
	}

}