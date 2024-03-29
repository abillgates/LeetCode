// 合并K个排序链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	void showList(ListNode* l) {
		while (l!=nullptr)
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
		while (cin>>n)
		{
			curr->next = new ListNode(n);
			curr = curr->next;
			if (cin.get() == '\n')
				break;
		}
		return head->next;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<int> number;
		for (int i = 0; i < lists.size(); i++) {
			while (lists[i]!=nullptr)
			{
				number.push_back(lists[i]->val);
				lists[i] = lists[i]->next;
			}
		}
		sort(number.begin(), number.end());
		ListNode* result = new ListNode(0);
		ListNode* curr = result;
		for (int i = 0; i < number.size(); i++) {
			curr->next = new ListNode(number[i]);
			curr = curr->next;
		}
		return result->next;
	}
	ListNode* mergeTwoList(ListNode* L1, ListNode* L2) {
		ListNode*p = L1, *q = L2;
		if (!p)return q;
		if (!q)return p;
		ListNode* NewList = new ListNode(0);
		ListNode* curr = NewList;
		while (p != nullptr&&q != nullptr) {
			if (p->val <= q->val) {
				curr->next = p;
				curr = curr->next;
				p = p->next;
			}
			else
			{
				curr->next = q;
				curr = curr->next;
				q = q->next;
			}
		}
		if (!p)
			curr->next = q;
		if (!q)
			curr->next = p;
		return NewList->next;
	}
	ListNode* mergeKLists1(vector<ListNode*>& lists) {
		int n = lists.size();
		while (n>1)
		{
			int k = (n + 1) / 2;
			for (int i = 0; i < n / 2; i++) {
				lists[i]=mergeTwoList(lists[i], lists[i + k]);
			}
			n = k;
		}
		return lists[0];
	}
};
int main()
{
	int n;
	vector<ListNode*> lists;
	cin >> n;
	/*ListNode* l1 = Solution().CreateList();
	Solution().showList(l1);
	ListNode* l2 = Solution().CreateList();
	Solution().showList(l2);
	Solution().showList(Solution().mergeTwoList(l1,l2));*/
	for (int i = 0; i < n; i++) {
		ListNode* l1 = Solution().CreateList();
		lists.push_back(l1);
	}
	for (auto i : lists) {
		Solution().showList(i);
		cout << endl;
	}
	Solution().showList(Solution().mergeKLists1(lists));
    //std::cout << "Hello World!\n"; 
	return 0;
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
