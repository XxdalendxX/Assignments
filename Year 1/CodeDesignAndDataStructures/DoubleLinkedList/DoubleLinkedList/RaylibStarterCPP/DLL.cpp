#include "DLL.h"
#include "Node.h"


	DLL::DLL()
	{
		head = new Node(0, nullptr, nullptr);
		tail = new Node(0, nullptr, head);
		head->next = tail;
	}

	DLL::~DLL()
	{
		while (IsEmpty() == false)
		{
			DeleteHeadNode();
		}
		delete tail;
		delete head;
	}

////////////////////////////////////////////////////////////////////////////////////////////
//Deletes or inserts nodes either at the head, tail or an assigned point in the list////////
////////////////////////////////////////////////////////////////////////////////////////////
	void DLL::InsertHeadNode(int value)
	{
		Node* newNode = new Node(value, head->next, head);
		head->next->previous = newNode;
		head->next = newNode;
	}

	void DLL::InsertTailNode(int value)
	{
		Node* newNode = new Node(value, tail, tail->previous);
		tail->previous->next = newNode;
		tail->previous = newNode;
	}

	void DLL::DeleteHeadNode()
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

	void DLL::DeleteTailNode()
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

	void DLL::InsertArbitraryNode(int position, int value)
	{
		if (NodeCount() < position)
		{
			return;
		}
		Node* insertPos = NodeFind(position);

		Node* newNode = new Node(value, insertPos->next, insertPos);
		insertPos->next = newNode;
	}

	void DLL::DeleteArbitraryNode(int position)
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
	//Counts total nodes, finds specific node for use, and checks if list is empty////////////// 
	////////////////////////////////////////////////////////////////////////////////////////////
	int DLL::NodeCount()
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

	Node* DLL::NodeFind(int position)
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

	bool DLL::IsEmpty()
	{
		if (head->next != tail)
		{
			return true;
		}
		return false;
	}
	////////////////////////////////////////////////////////////////////////////////////////////
	//Returns current head and tail values in the list./////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////
	int DLL::ReturnHeadValue()
	{
		return head->next->_value;
	}

	int DLL::ReturnTailValue()
	{
		return tail->previous->_value;
	}
	////////////////////////////////////////////////////////////////////////////////////////////
	//Sorts the list in ascending order/////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////
	void DLL::ListSort()
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