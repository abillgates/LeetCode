// LeetCode-203-移除链表元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	ListNode* createList() {
		ListNode head(0);
		ListNode* p = &head;
		int n = 0;
		while (cin>>n)
		{
			p->next = new ListNode(n);
			p = p->next;
			if (cin.get() == '\n')
				break;
		}
		return head.next;
	}
	void showList(ListNode* head) {
		ListNode* p = head;
		while (p)
		{
			cout << p->val;
			if (p->next) {
				cout << "->";
			}
			p = p->next;
		}
		cout << endl;
	}
	ListNode* removeElements0(ListNode* head, int val) {
		ListNode* p = head;
		if (p == nullptr || p->val == val && p->next == nullptr) {
			return nullptr;
		}
		while (p&&p->val==val)
		{
			head = p->next;
			p = p->next;
		}
		if (!head) {
			return nullptr;
		}
		p = head;
		while (p&&p->next)
		{
			while (p&&p->next&&p->next->val == val)
			{
				p->next = p->next->next;
			}
			p = p->next;
		}
		return head;
	}
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* node = new ListNode(0);
		ListNode* p = head;
		head = node;
		while (p)
		{
			if (p->val == val) {			
				p = p->next;
			}
			else
			{
				node->next = p;
				node = node->next;	
				p = p->next;
			}	
		}
		node->next = nullptr;
		return head->next;
	}
};
int main()
{
	Solution::ListNode* L1 = Solution().createList();
	Solution().showList(L1);
	Solution::ListNode* L2 = Solution().removeElements(L1,1);
	Solution().showList(L2);
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
