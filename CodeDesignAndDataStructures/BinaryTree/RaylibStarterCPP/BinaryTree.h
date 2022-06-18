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

private:

	bool FindNode();

public:

	TreeNode* m_root;
};
