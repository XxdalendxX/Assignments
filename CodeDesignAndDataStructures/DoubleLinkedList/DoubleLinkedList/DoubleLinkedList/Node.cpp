#include"Node.h"

Node::Node(int value, Node* next, Node* Previous)
{
	head = new Node( 0, nullptr, nullptr );
	tail = new Node( 0, nullptr, head );
	head->next = tail;
}
Node::~Node()
{

}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Node::InsertHeadNode(int value)
{
	Node* newNode = new Node(value, head, head->next);
	head->next = newNode;
}

void Node::InsertTailNode(int value)
{
	Node* newNode = new Node(value, tail->previous, tail);
	tail->previous = newNode;
}

void Node::DeleteHeadNode()
{
	Node* node = tail->next;
	node->next->previous = head;
	node->previous->next = node->next;
	delete node;
}

void Node::DeleteTailNode()
{
	Node* node = tail->previous;
	node->next->previous = node->previous;
	node->previous->next = tail;
	delete node;
}

void Node::InsertArbitraryNode(int position, int value)
{
	if (NodeCount() < position)
	{
		return;
	}
	Node* insertPos = NodeFind(position);

	Node* newNode = new Node(value, insertPos, insertPos->next);
	insertPos->next = newNode;
}

void Node::DeleteArbitraryNode(int position)
{
	if (NodeCount() < position)
	{
		return;
	}
	Node* nodePos = NodeFind(position);

	nodePos->next->previous = nodePos->previous;
	nodePos->previous->next = tail;
	delete nodePos;
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
int Node::NodeCount()
{
	int count = 0;
	Node* currentNode = head;
	while (currentNode != tail)
	{
		if (currentNode->next != tail)
		{
			count++;
		}
		currentNode->next = currentNode;
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
		currentNode->next = currentNode;
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
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
int Node::ReturnHeadValue()
{
	return head->next->value;
}

int Node::ReturnTailValue()
{
	return tail->previous->value;
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Node::ListSort()
{
	Node* currentNode = head->next;
	bool swapped = true;
	while (swapped = true)
	{
		bool swap = false;
		while (currentNode != tail)
		{
			if (currentNode->value > currentNode->next->value)
			{
				swap = true;
				int temp = currentNode->value;
				currentNode->value = currentNode->next->value;
				currentNode->next->value = temp;
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
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
int main() 
{
	


	return 0;
}