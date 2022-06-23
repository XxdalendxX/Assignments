#include "BinaryTree.h"
#include "TreeNode.h"


BinaryTree::BinaryTree()
{
	m_root = nullptr;
}

BinaryTree::~BinaryTree()
{

}

//////////////////////////////////////////////////////////
//public functions accesible by the whole program
//////////////////////////////////////////////////////////

bool BinaryTree::IsEmpty() const
{
	return (m_root == nullptr);
}

void BinaryTree::Add(int value)
{
	TreeNode* node = new TreeNode(value);
	if (IsEmpty() == true)
	{
		m_root = node;
	}
	else
	{
		TreeNode* currentNode = m_root;
		bool placed = false;
		while (placed == false)
		{
			if (node-> m_value < currentNode->m_value)
			{
				if (currentNode->left == nullptr)
				{
					currentNode = node;
					placed = true;
				}
				else
				{
					currentNode->left = currentNode->left;
				}
			}
			else
			{
				if (currentNode->right == nullptr)
				{
					currentNode->right = node;
					placed = true;
				}
				else
				{
					currentNode = currentNode->right;
				}
			}
		}
	}
}

void BinaryTree::Remove(int value)
{
	FindNode();
}

TreeNode* BinaryTree::Find(int value)
{
	return m_root;
}

//////////////////////////////////////////////////////////
//Private functions exclusive to this .cpp file
//////////////////////////////////////////////////////////

bool BinaryTree::FindNode()
{
	return false;
}