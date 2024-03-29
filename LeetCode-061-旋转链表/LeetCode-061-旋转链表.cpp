// LeetCode-061-旋转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include<vector>
using namespace std;
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
			if (p->next)
				cout << "->";
			p = p->next;
		}
		cout << endl;
	}
	ListNode* rotateRight0(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		vector<int> num;
		ListNode* p = head;
		while (p)
		{
			num.push_back(p->val);
			p = p->next;
		}
		int n = num.size();
		k = k % n;
		reverse(num.begin(), num.end());
		reverse(num.begin(), num.begin() + k);
		reverse(num.begin() + k, num.end());
		p = head;
		for (int i = 0; i < n; i++) {
			p->val = num[i];
			p = p->next;
		}
		return head;
	}
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		int n = 0;		
		ListNode* p = head;
		while (p->next)
		{
			p = p->next;
			n++;	
		}
		k = k % (++n);
		if (k == 0)
			return head;
		p->next = head;
		for (int i = 0; i < n - k; i++) {
			p = p->next;
		}
		ListNode* newtail = p;
		ListNode* newhead = p->next;
		newtail->next = nullptr;
		return newhead;
	}
};
int main()
{
	Solution::ListNode* L1 = Solution().createList();
	Solution().showList(L1);
	Solution().showList(Solution().rotateRight(L1,4));
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
//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
//
//示例 1 :
//
//输入: 1->2->3->4->5->NULL, k = 2
//	输出 : 4->5->1->2->3->NULL
//	解释 :
//	向右旋转 1 步 : 5->1->2->3->4->NULL
//		向右旋转 2 步 : 4->5->1->2->3->NULL
//		示例 2 :
//
//输入: 0->1->2->NULL, k = 4
//	输出 : 2->0->1->NULL
//	解释 :
//	向右旋转 1 步 : 2->0->1->NULL
//		向右旋转 2 步 : 1->2->0->NULL
//		向右旋转 3 步 : 0->1->2->NULL
//		向右旋转 4 步 : 2->0->1->NULL
//
//		来源：力扣（LeetCode）
//		链接：https ://leetcode-cn.com/problems/rotate-list
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。