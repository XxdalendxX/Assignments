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
	TreeNode* node = nullptr;
	TreeNode* parent = nullptr;
	if (FindNode(value, node, parent) == true)
	{
		if (node->CheckRight() == true)
		{
			TreeNode* selectNode = node;
			TreeNode* selectNodeParent = node;
			selectNode = selectNode->right;
			while (selectNode->left != nullptr)
			{
				selectNodeParent = selectNode;
				selectNode = selectNode->left;
			}
			node->m_value = selectNode->m_value;
			if (selectNodeParent->left == selectNode)
			{
				selectNodeParent->left = selectNode->right;
			}
			else
			{
				selectNodeParent->right = selectNode->right;
			}
			delete selectNode;
		}
		else
		{
			if (parent != nullptr)
			{
				if (parent->left == node)
				{
					parent->left = node->left;
				}
				else
				{
					parent->right = node->left;
				}
			}
			else
			{
				m_root = node->left;
			}
			delete node;
		}
	}
}

TreeNode* BinaryTree::Find(int value)
{
	TreeNode* node = nullptr;
	TreeNode* parent = nullptr;
	return (FindNode(value, node, parent) ? node: nullptr);
}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_root, 900, 40, 400, selected);
}

//////////////////////////////////////////////////////////
//Private functions exclusive to this .cpp file
//////////////////////////////////////////////////////////

bool BinaryTree::FindNode(int searchVal, TreeNode*& node, TreeNode*& parentNode)
{
	parentNode = nullptr;
	node = m_root;
	if (IsEmpty() == true)
	{
		return false;
	}
	else
	{
		while (node != nullptr)
		{
			if (searchVal < node->m_value)
			{
				parentNode = node;
				node = node->left;
			}
			else if (searchVal > node->m_value)
			{
				parentNode = node;
				node = node->right;
			}
			else
			{
				return true;
			}
		}
	}
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