#include "pch.h"
#include "CppUnitTest.h"
#include "BinaryTree.h"
#include "TreeNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unittests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(NodeGetValue)
		{
			int value = 10;
			TreeNode node(value);
			Assert::AreEqual(value, node.GetValue());
		}

		TEST_METHOD(NodeCheckLeft)
		{
			TreeNode node(69);
			Assert::AreEqual(false, node.CheckLeft());
		}

		TEST_METHOD(NodeCheckRight)
		{
			TreeNode node(69);
			Assert::AreEqual(false, node.CheckRight());
		}

		TEST_METHOD(NodeSetRight)
		{
			TreeNode node(69);
			TreeNode* rightNode = new TreeNode(420);
			node.SetRight(rightNode);
			Assert::AreEqual(true, node.CheckRight());
		}

		TEST_METHOD(NodeSetLeft)
		{
			TreeNode node(69);
			TreeNode* leftNode = new TreeNode(420);
			node.SetLeft(leftNode);
			Assert::AreEqual(true, node.CheckLeft());
		}

		TEST_METHOD(NodeSetValue)
		{
			TreeNode node(69);
			node.SetValue(420);
			Assert::AreEqual(420, node.GetValue());
		}

		TEST_METHOD(NodeGetLeft)
		{
			TreeNode node(69);
			TreeNode* leftNode = new TreeNode(420);
			node.SetLeft(leftNode);
			Assert::IsTrue(leftNode == node.GetLeft());
		}

		TEST_METHOD(NodeGetRight)
		{
			TreeNode node(69);
			TreeNode* rightNode = new TreeNode(420);
			node.SetRight(rightNode);
			Assert::IsTrue(rightNode == node.GetRight());
		}

		TEST_METHOD(TreeIsEmpty)
		{
			BinaryTree tree;
			Assert::IsTrue(true == tree.IsEmpty());
		}

		TEST_METHOD(TreeIsNotEmpty)
		{
			BinaryTree tree;
			TreeNode* node = new TreeNode(10);
			tree.m_root = node;
			Assert::IsTrue(false == tree.IsEmpty());
		}

		TEST_METHOD(TreeAddNodeToRoot)
		{
			BinaryTree tree;
			tree.Add(10);
			Assert::AreEqual(10, tree.m_root->m_value);
		}

		TEST_METHOD(TreeAddNodeRightOfRoot)
		{
			BinaryTree tree;
			tree.Add(10);
			TreeNode* node = tree.m_root;
			tree.Add(81);
			Assert::AreEqual(81, node->right->m_value);
		}

		TEST_METHOD(TreeAddNodeLeftOfRoot)
		{
			BinaryTree tree;
			tree.Add(81);
			TreeNode* node = tree.m_root;
			tree.Add(10);
			Assert::AreEqual(10, node->left->m_value);
		}
	};
}
