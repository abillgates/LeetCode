// LeetCode-101-对称二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
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
		TreeNode *root;
		int data;
		cin >> data;
		if (cin.fail()) {
			root = nullptr;
			//这两个恢复输入流读取函数的顺序不能反
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
	bool isSymmetric0(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		return isSubSymmetric(root->left, root->right);
	}
	bool isSubSymmetric(TreeNode* left, TreeNode* right) {
		if (!left && !right) {
			return true;
		}
		else if (!left || !right) {
			return false;
		}
		else if (left->val == right->val) {
			return isSubSymmetric(left->left, right->right) && isSubSymmetric(left->right, right->left);
		}
		else {
			return false;
		}
	}
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		queue<TreeNode*> q;
		q.push(root->left);
		q.push(root->right);
		while (!q.empty())
		{
			TreeNode* t1 = q.front();
			q.pop();
			TreeNode* t2 = q.front();
			q.pop();
			if (!t1 && !t2) {
				continue;
			}
			if (!t1 || !t2) {
				return false;
			}
			if (t1->val == t2->val) {
				q.push(t1->left);
				q.push(t2->right);
				q.push(t1->right);
				q.push(t2->left);
			}
			else {
				return false;
			}
		}
		return true;
	}
	void preOrder(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		cout << root->val<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
};
int main()
{
	TreeNode *T = Solution().createTree();
	Solution().preOrder(T);
	cout << endl;
	cout << Solution().isSymmetric(T);
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
//给定一个二叉树，检查它是否是镜像对称的。
// 1 2 3 # # 4 # # 2 4 # # 3 # #
//例如，二叉树 [1, 2, 2, 3, 4, 4, 3] 是对称的。
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//但是下面这个 [1, 2, 2, null, 3, null, 3] 则不是镜像对称的:
//
//1
/// \
//2   2
//\   \
//3    3
//说明:
//
//如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/symmetric-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。