// LeetCode-112-路径总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "pch.h"
#include <iostream>
#include<stack>
using namespace std;
class Solution {
public:
	struct TreeNode
	{
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) {
			val = x;
			left = nullptr;
			right = nullptr;
		}
	};
	TreeNode* createTree() {
		TreeNode* root;
		int data;
		cin >> data;
		if (cin.fail()) {
			root = nullptr;
			cin.clear();
			cin.ignore();
		}
		else {
			root = new TreeNode(data);
			root->left = createTree();
			root->right = createTree();
		}
		return root;
	}
	void preOrder(TreeNode* root) {
		if (!root) {
			return;
		}
		cout << root->val << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
	bool hasPathSum0(TreeNode* root, int sum) {
		if (!root ) {
			return false;
		}
		if (!root->left&&!root->right && sum==root->val) {
			return true;
		}
		return hasPathSum0(root->left, sum - root->val) || hasPathSum0(root->right, sum - root->val);
	}
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) {
			return false;
		}
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty())
		{
			TreeNode* t = s.top();
			s.pop();
			if (!t->left&&!t->right&&t->val == sum)
				return true;
			if (t->left) {
				t->left->val += t->val;
				s.push(t->left);
			}		
			if (t->right) {
				t->right->val += t->val;
				s.push(t->right);
			}		
		}
		return false;
	}
};
int main()
{
	//5 4 11 7 # # 2 # # # 8 13 # # 4 # 1 # #
	Solution s;
	Solution::TreeNode* T1 = s.createTree();
	s.preOrder(T1);
	cout << endl;
	cout << s.hasPathSum(T1,22);
    //std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
//给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
//
//说明 : 叶子节点是指没有子节点的节点。
//
//	示例 :
//给定如下二叉树，以及目标和 sum = 22，
//
//5
/// \
//4   8
///   / \
//11  13  4
/// \      \
//7    2      1
//返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/path-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。