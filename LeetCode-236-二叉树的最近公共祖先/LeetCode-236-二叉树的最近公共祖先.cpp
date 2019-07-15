// LeetCode-236-二叉树的最近公共祖先.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include<map>
#include<set>
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
			cin.clear();
			cin.ignore();
			root = nullptr;
		}
		else {
			root = new TreeNode(data);
			root->left = createTree();
			root->right = createTree();
		}
		return root;
	}
	void preOrder(TreeNode* root) {
		if (!root)
			return;
		cout << root->val << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q)
			return root;
		TreeNode* left, *right;
		left = lowestCommonAncestor(root->left, p, q);
		right = lowestCommonAncestor(root->right, p, q);
		if (left&&right)
			return root;
		return left ? left : right;
	}
	TreeNode* lowestCommonAncestor0(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> st;
		st.push(root);
		map<TreeNode*, TreeNode*> m;
		m.insert({ root,nullptr });
		while (m.count(p)==0||m.count(q)==0)
		{
			TreeNode* t = st.top();
			st.pop();
			if (t->left) {
				st.push(t->left);
				m.insert({ t->left,t });
			}	
			if (t->right) {
				st.push(t->right);
				m.insert({ t->right,t });
			}				
		}
		set<TreeNode*> s;
		while (p)
		{	
			s.insert(p);
			p = m[p];
			/*if (p)
				cout << p->val << "==";*/
		}
		while (s.count(q)==0)
		{
			q = m[q];
		}
		return q;
	}
};
int main()
{
	//3 5 6 # # 2 7 # # 4 # # 1 0 # # 8 # #
	Solution s;
	Solution::TreeNode* T1 = s.createTree();
	s.preOrder(T1);
	cout << endl;
	cout << s.lowestCommonAncestor0(T1, T1->left, T1->left->right->right)->val;
    //std::cout << "Hello World!\n"; 
}
//refe
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//
//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
//
//例如，给定如下二叉树 : root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
//3 5 6 # # 2 7 # # 4 # # 1 0 # # 8 # #
//
//
//
//
//	示例 1:
//
//输入: root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1
//	输出 : 3
//	解释 : 节点 5 和节点 1 的最近公共祖先是节点 3。
//	示例 2 :
//
//输入: root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 4
//	输出 : 5
//	解释 : 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
//
//
//	说明 :
//
//	所有节点的值都是唯一的。
//		p、q 为不同节点且均存在于给定的二叉树中。
//
//		来源：力扣（LeetCode）
//		链接：https ://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。