// LeetCode-100-相同的树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	bool isSameTree(TreeNode* p, TreeNode* q) {

	}
};
int main()
{
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
//给定两个二叉树，编写一个函数来检验它们是否相同。
//
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//
//示例 1 :
//
//输入:			 1   1
//				/ \ / \
//			   2  3 2  3
//
//	[1, 2, 3], [1, 2, 3]
//
//	输出: true
//	示例 2 :
//
//	输入 :  1          1
//			/           \
//	       2             2
//
//	[1, 2], [1, null, 2]
//
//	输出: false
//	示例 3 :
//
//	输入 : 1         1
//	/ \ / \
//	2   1     1   2
//
//	[1, 2, 1], [1, 1, 2]
//
//	输出: false
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/same-tree
//		  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。