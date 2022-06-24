#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"


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
					currentNode->left = node;
					placed = true;
				}
				else
				{
					currentNode = currentNode->left;
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

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_root, 900, 40, 400, selected);
}

//////////////////////////////////////////////////////////
//Private functions exclusive to this .cpp file
//////////////////////////////////////////////////////////

bool BinaryTree::FindNode()
{
	return false;
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{

	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->CheckLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);

			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->CheckRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}