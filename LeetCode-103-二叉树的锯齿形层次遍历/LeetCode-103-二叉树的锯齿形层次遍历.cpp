// LeetCode-103-二叉树的锯齿形层次遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	TreeNode(int x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
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
	void preOrder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		cout << root->val<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == nullptr) {
			return {};
		}
		vector<vector<int>> res;		
		queue<TreeNode*> q;
		bool flag = 1;
		q.push(root);
		while (!q.empty()) {
			vector<int> level;
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
			if (!flag) {
				reverse(level.begin(), level.end());
			}
			res.push_back(level);
			flag = !flag;
		}
		return res;
	}
};
int main()
{
	Solution s;
	TreeNode* T = s.createTree();
	s.preOrder(T);
	cout << endl;
	auto res = s.zigzagLevelOrder(T);
	//cout << res.size()<<endl;
	for (auto i : res) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
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
//给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//例如：
//给定二叉树 [3, 9, 20, null, null, 15, 7],
//
//3
/// \
//9  20
/// \
//15   7
//返回锯齿形层次遍历如下：
//
//[
//	[3],
//	[20, 9],
//	[15, 7]
//]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。