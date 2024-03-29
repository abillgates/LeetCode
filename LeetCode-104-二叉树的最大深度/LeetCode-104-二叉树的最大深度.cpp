// LeetCode-104-二叉树的最大深度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
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
		if (root == nullptr) {
			return;
		}
		cout << root->val << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
	int maxDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return left > right ? left + 1 : right + 1;
	}
};
int main()
{
	Solution s;
	Solution::TreeNode* T = s.createTree();
	s.preOrder(T);
	cout << endl;
	cout << s.maxDepth(T);
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
//给定一个二叉树，找出其最大深度。
//
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//
//说明 : 叶子节点是指没有子节点的节点。
//
//	示例：
//	给定二叉树[3, 9, 20, null, null, 15, 7]，
//
//	3
//	/ \
//	9  20
//	/ \
//	15   7
//	返回它的最大深度 3 。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/maximum-depth-of-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。