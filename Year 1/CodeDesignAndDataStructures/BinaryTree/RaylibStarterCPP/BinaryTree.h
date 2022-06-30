#pragma once

class TreeNode;

class BinaryTree
{
public:

	BinaryTree();
	~BinaryTree();

	void Add(int value);
	void Remove(int value);
	TreeNode* Find(int value);

	bool IsEmpty() const;
	void Draw(TreeNode* selected);

private:

	bool FindNode(int searchVal, TreeNode*& node, TreeNode*& parentNode);
	void Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected);

public:

	TreeNode* m_root;
};
