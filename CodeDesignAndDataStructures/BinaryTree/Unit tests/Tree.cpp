#include "pch.h"
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
//////////////////////////////////////////////////////////
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
			if (node->m_value < currentNode->m_value)
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

}

TreeNode* BinaryTree::Find(int value)
{
	return m_root;
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

bool BinaryTree::FindNode()
{
	return false;
}