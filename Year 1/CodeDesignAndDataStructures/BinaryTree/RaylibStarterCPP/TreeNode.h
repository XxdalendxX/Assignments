#pragma once

class TreeNode
{
public:

	TreeNode(int value);
	~TreeNode();

	bool CheckLeft();
	bool CheckRight();

	int GetValue();
	TreeNode* GetLeft();
	TreeNode* GetRight();

	void SetValue(int value);
	void SetLeft(TreeNode* node);
	void SetRight(TreeNode* node);

	void Draw(int x, int y, bool selected = false);

public:
	int m_value;

	TreeNode* left;
	TreeNode* right;
};