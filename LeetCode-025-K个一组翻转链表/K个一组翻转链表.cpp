// K个一组翻转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	void showList(ListNode* node) {
		while (node)
		{
			cout << node->val;
			if (node->next)
				cout << "->";
			node = node->next;
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
	ListNode* reverseList(ListNode* L) {
		//ListNode* head = new ListNode(0);
		ListNode* p, *q,*r;
		p = L; 
		if (!p)return nullptr;
		q = L->next;
		if (!q)return p;
		r = q->next;
		L->next = nullptr;
		while (r)
		{
			q->next = p;
			p = q;
			q = r;
			r = r->next;
		}
		q->next = p;
		//head->next = q;
		return q;
	}
	ListNode* reverseKGroup(ListNode* head, int k) {
		int temp = k;
		ListNode* phead,*frontLast,*nextBegin;
		phead=frontLast=nextBegin=head;
		if (head == nullptr||head->next==nullptr)return head;
		while (--temp) {
			frontLast = frontLast->next;
			if (frontLast == nullptr)
				return phead;
		}
		nextBegin = frontLast->next;	
		ListNode* p, *q, *r;
		p = head;
		//if (!p)return nullptr;
		q = head->next;
		if (q==nextBegin)return p;
		r = q->next;
		head->next = reverseKGroup(nextBegin,k);
		while (r!=nextBegin)
		{
			q->next = p;
			p = q;
			q = r;
			r = r->next;
		}
		q->next = p;
		return q;
	}
};
int main()
{
	Solution::ListNode* L1 = Solution().createList();
	Solution().showList(L1);
	//Solution().showList(Solution().reverseList(L1));
	Solution().showList(Solution().reverseKGroup(L1,1));
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
