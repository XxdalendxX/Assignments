#include "TreeNode.h"
#include "raylib.h"
#include <string>

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

bool TreeNode::CheckLeft()
{
	return (left != nullptr);
}

bool TreeNode::CheckRight()
{
	return (right != nullptr);
}

/////////////////////////////////////////////////////////////
//Gets node variables for use or display
/////////////////////////////////////////////////////////////

int TreeNode::GetValue()
{
	return m_value;
}

TreeNode* TreeNode::GetLeft()
{
	return left;
}

TreeNode* TreeNode::GetRight()
{
	return right;
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

/////////////////////////////////////////////////////////////
//Draw function for the nodes
/////////////////////////////////////////////////////////////

void TreeNode::Draw(int x, int y, bool selected)
{
	static char buffer[10];

	sprintf(buffer, "%d", m_value);

	DrawCircle(x, y, 30, YELLOW);

	if (selected == true)
		DrawCircle(x, y, 28, GREEN);
	else
		DrawCircle(x, y, 28, BLACK);


	DrawText(buffer, x - 12, y - 10, 12, WHITE);
}