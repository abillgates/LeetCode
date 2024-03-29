// LeetCode-637-二叉树的层平均值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include<vector>
#include<queue>
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
	vector<double> averageOfLevels(TreeNode* root) {
		if (!root) {
			return{};
		}
		vector<double> res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int n = q.size();
			double sum = 0;
			for (int i = 0; i < n; i++) {
				TreeNode *t = q.front();
				q.pop();
				sum = sum + t->val;
				if (t->left) {
					q.push(t->left);
				}
				if (t->right) {
					q.push(t->right);
				}
			}
			res.push_back(sum / double(n));
		}
		return res;
	}
};
int main()
{
	Solution s;
	Solution::TreeNode* T = s.createTree();
	s.preOrder(T);
	cout << endl;
	for (double i : s.averageOfLevels(T)) {
		cout << i << endl;
	}
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
//给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
//
//示例 1:
//
//输入:
//  3
// / \
//9  20
//   / \
// 15   7
//输出: [3, 14.5, 11]
//	解释 :
//	第0层的平均值是 3, 第1层是 14.5, 第2层是 11. 因此返回[3, 14.5, 11].
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/average-of-levels-in-binary-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。