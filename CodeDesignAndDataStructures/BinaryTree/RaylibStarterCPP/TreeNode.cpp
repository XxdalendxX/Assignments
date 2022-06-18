#include "TreeNode.h"

TreeNode::TreeNode(int value)
{
	m_value = value;
	left = nullptr;
	right = nullptr;
}
TreeNode::~TreeNode()
{

}

/////////////////////////////////////////////////////////////
//Checks left and right nodes to see if they have been filled 
/////////////////////////////////////////////////////////////

bool TreeNode::CheckLeft(TreeNode* node)
{
	return (node->left != nullptr);
}

bool TreeNode::CheckRight(TreeNode* node)
{
	return (node->right != nullptr);
}

/////////////////////////////////////////////////////////////
//Gets node variables for use or display
/////////////////////////////////////////////////////////////

int TreeNode::GetValue(TreeNode* node)
{
	return node->m_value;
}

TreeNode* TreeNode::GetLeft(TreeNode* node)
{
	return node->left;
}

TreeNode* TreeNode::GetRight(TreeNode* node)
{
	return node->right;
}

/////////////////////////////////////////////////////////////
//Sets node variables to specific nodes or intergers.
/////////////////////////////////////////////////////////////

void TreeNode::SetValue(int value)
{
	m_value = value;
}

void TreeNode::SetLeft(TreeNode* node)
{
	left = node;
}

void TreeNode::SetRight(TreeNode* node)
{
	right = node;
}