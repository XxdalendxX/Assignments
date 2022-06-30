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

		TEST_METHOD(TreeFindNode)
		{
			BinaryTree tree;
			tree.Add(81);
			tree.Add(10);
			tree.Add(20);
			tree.Add(69);
			tree.Add(420);
			tree.Add(70);
			tree.Add(18);
			tree.Add(4);
			tree.Add(32);
			tree.Add(99);
			TreeNode* node = nullptr;
			node = tree.Find(32);
			Assert::IsNotNull(node);
			int nodeval = node->m_value;
			Assert::AreEqual(32, node->m_value);
		}

		TEST_METHOD(TreeRemoveNoBranch)
		{
			BinaryTree tree;
			tree.Add(81);
			tree.Add(10);
			tree.Add(20);
			tree.Add(69);
			tree.Add(420);
			tree.Add(70);
			tree.Add(18);
			tree.Add(4);
			tree.Add(32);
			tree.Add(99);
			tree.Add(101);
			tree.Remove(420);
			Assert::IsNull(tree.Find(32));
		}

		TEST_METHOD(TreeRemove1Branch)
		{
			BinaryTree tree;
			tree.Add(81);
			tree.Add(10);
			tree.Add(20);
			tree.Add(69);
			tree.Add(420);
			tree.Add(70);
			tree.Add(18);
			tree.Add(4);
			tree.Add(32);
			tree.Add(99);
			tree.Add(90);
			tree.Remove(99);
			Assert::IsNull(tree.Find(99));
		}

		TEST_METHOD(TreeRemove2Branch)
		{
			BinaryTree tree;
			tree.Add(81);
			tree.Add(10);
			tree.Add(20);
			tree.Add(69);
			tree.Add(420);
			tree.Add(70);
			tree.Add(18);
			tree.Add(4);
			tree.Add(32);
			tree.Add(99);
			tree.Add(101);
			tree.Remove(10);
			Assert::IsNull(tree.Find(10));
		}
	};
}
