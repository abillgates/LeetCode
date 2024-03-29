// LeetCode-83-删除排序链表中的重复元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	void showList(ListNode* head) {
		ListNode* p = head;
		while (p)
		{
			cout << p->val;
			if (p->next)
				cout << "-->";
			p = p->next;
		}
		cout << endl;
	}
	ListNode* createList() {
		ListNode* head = new ListNode(0);
		ListNode* curr = head;
		int n;
		while (cin>>n)
		{
			curr->next = new ListNode(n);
			curr = curr->next;
			if (cin.get() == '\n')
				break;
		}
		return head->next;
	}
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
			return NULL;
		ListNode* curr=head, *temp;
		for (;curr->next; curr = curr->next) {
			while (curr->val==curr->next->val)
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
				if (!curr->next)
					break;
			}
			if (!curr->next)
				break;
		}
		return head;
	}
};
int main()
{
	Solution::ListNode* list = Solution().createList();
	Solution().showList(list);
	Solution().showList(Solution().deleteDuplicates(list));
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
