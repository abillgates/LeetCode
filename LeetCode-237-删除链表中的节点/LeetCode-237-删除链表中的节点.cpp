// LeetCode-237-删除链表中的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "pch.h"
#include <iostream>
using namespace std;
class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) {
			val = x;
			next = nullptr;
		}
	};
	ListNode* createList() {
		ListNode* head=new ListNode(0);
		ListNode* curr = head;
		int n = 0;
		while (cin>>n)
		{
			curr->next = new ListNode(n);
			curr = curr->next;
			if (cin.get() == '\n')
				break;
		}
		return head->next;
	}
	void showList(ListNode* head) {
		ListNode* p = head;
		while (p)
		{
			cout << p->val;
			if (p->next)
				cout << "->";
			p = p->next;
		}
		cout << endl;
	}
	void deleteNode(ListNode* node) {
		ListNode* p = node->next;
		node->val = p->val;
		node->next = p->next;
		delete p;
	}
};
int main()
{
	Solution s;
	Solution::ListNode* L1 = s.createList();
	s.showList(L1);
	s.deleteNode(L1->next);
	s.showList(L1);
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
//请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
//
//现有一个链表 -- head = [4, 5, 1, 9]，它可以表示为:
//
//
//
//
//
//示例 1:
//
//输入: head = [4, 5, 1, 9], node = 5
//	输出 : [4, 1, 9]
//	解释 : 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
//	示例 2 :
//
//	输入 : head = [4, 5, 1, 9], node = 1
//	输出 : [4, 5, 9]
//	解释 : 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
//
//
//	说明 :
//
//	链表至少包含两个节点。
//	链表中所有节点的值都是唯一的。
//	给定的节点为非末尾节点并且一定是链表中的一个有效节点。
//	不要从你的函数中返回任何结果。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/delete-node-in-a-linked-list
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。