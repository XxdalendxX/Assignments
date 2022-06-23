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
	};
}
