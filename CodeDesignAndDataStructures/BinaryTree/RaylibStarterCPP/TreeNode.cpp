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

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

bool TreeNode::CheckLeft(TreeNode* node)
{
	return (node->left != nullptr);
}

bool TreeNode::CheckRight(TreeNode* node)
{
	return (node->right != nullptr);
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

void TreeNode::SetValue(int value)
{

}

void TreeNode::SetLeft(TreeNode* node)
{

}

void TreeNode::SetRight(TreeNode* node)
{

}