#pragma once

class TreeNode
{
public:

	TreeNode(int value);
	~TreeNode();

	bool CheckLeft(TreeNode* node);
	bool CheckRight(TreeNode* node);

	int GetValue(TreeNode* node);
	TreeNode* GetLeft(TreeNode* node);
	TreeNode* GetRight(TreeNode* node);

	void SetValue(int value);
	void SetLeft(TreeNode* node);
	void SetRight(TreeNode* node);

public:
	int m_value;

	TreeNode* left;
	TreeNode* right;
};