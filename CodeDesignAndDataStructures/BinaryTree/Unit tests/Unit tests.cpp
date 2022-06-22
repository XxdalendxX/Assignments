#include "pch.h"
#include "CppUnitTest.h"
#include "BinaryTree.h"
#include "TreeNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Unittests
{
	TEST_CLASS(TreeNode)
	{
	public:
		
		TEST_METHOD(NodeGetValue)
		{
			int value = 10;
			TreeNode node(value);
			Assert::AreEqual(value, node.GetValue());
		}
	};
}
