// LeetCode-102-二叉树的层次遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<queue>
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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr) {
			return {};
		}
		queue<TreeNode*> q;
		vector<vector<int>> res;
		vector<int> level;
		q.push(root);
		while (!q.empty())
		{
			int n = q.size();
			for (int i = 0; i < n; i++) {
				TreeNode* t = q.front();
				q.pop();
				level.push_back(t->val);
				if (t->left) {
					q.push(t->left);
				}
				if (t->right) {
					q.push(t->right);
				}
			}
			res.push_back(level);
			level.clear();
		}
		return res;
	}
	void preOrder(TreeNode* root) {
		if (!root) {
			return;
		}
		cout << root->val<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
};
int main()
{
	TreeNode* T1 = Solution().createTree();
	Solution().preOrder(T1);
	cout << endl;
	auto res = Solution().levelOrder(T1);
	for (auto i : res) {
		for (int j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	//cout << res.size();
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
//给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
//   3 9 # # 20 15 # # 7 # #
//例如 :
//给定二叉树: [3, 9, 20, null, null, 15, 7],
//
//	  3
//	 / \
//	9  20
//	  /  \
//	 15   7
//	返回其层次遍历结果：
//
//	[
//		[3],
//		[9, 20],
//		[15, 7]
//	]
//
//	   来源：力扣（LeetCode）
//		   链接：https ://leetcode-cn.com/problems/binary-tree-level-order-traversal
//	   著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。