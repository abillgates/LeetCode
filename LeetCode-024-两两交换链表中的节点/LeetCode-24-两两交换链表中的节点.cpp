// LeetCode-24-两两交换链表中的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	void showList(ListNode* l) {
		while (l != nullptr)
		{
			cout << l->val;
			if (l->next)
				cout << "->";
			l = l->next;
		}
		cout << endl;
	}
	ListNode* CreateList() {
		ListNode* head = new ListNode(0);
		ListNode* curr = head;
		int n;
		while (cin >> n)
		{
			curr->next = new ListNode(n);
			curr = curr->next;
			if (cin.get() == '\n')
				break;
		}
		return head->next;
	}
	ListNode* swapPairs(ListNode* head) {
		if (head==nullptr||head->next == nullptr)
			return head;
	/*	ListNode* Prehead = new ListNode(0);
		Prehead->next = head;*/
		ListNode*last;
		last = head->next;
		head->next = swapPairs(last->next);
		last->next = head;
		return last;
	}
};
int main()
{
	Solution::ListNode* L1 = Solution().CreateList();
	Solution().showList(L1);
	Solution().showList(Solution().swapPairs(L1));
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
