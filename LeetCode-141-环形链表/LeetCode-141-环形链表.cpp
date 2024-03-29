// LeetCode-141-环形链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<set>
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
		for (; p; p = p->next) {
			cout << p->val;
			if (p->next)
				cout << "->";
		}
		cout << endl;
	}
	ListNode* createList() {
		ListNode* head=new ListNode(0);
		ListNode* p = head;
		int n=0;
		while (cin>>n)
		{
			p->next = new ListNode(n);
			p = p->next;
			if (cin.get() == '\n')
				break;
		}
		return head->next;
	}
	void createCycle(ListNode*& head, int pos) {
		if (pos == -1) {
			return;
		}
		ListNode* last=head,*lastNext=head;
		while (last->next)
		{
			if (pos) {
				lastNext = lastNext->next;
				pos--;
			}
			last = last->next;
		}
		last->next = lastNext;
	}
	bool hasCycle0(ListNode *head) {
		set<ListNode*> check;
		ListNode* p = head;
		for (; p; p = p->next) {
			if (check.insert(p).second==false)
			{
				return true;
			}
		}
		return false;
	}
	bool hasCycle(ListNode *head) {
		if (head == nullptr|| head->next == nullptr) {
			return false;
		}
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (slow!=nullptr&&fast!=nullptr)
		{
			if (slow == fast) {
				return true;
			}
			if (fast->next) {
				fast = fast->next->next;
				slow = slow->next;
			}
			else
				break;
		}
		return false;
	}
};
int main()
{
	Solution::ListNode* L1 = Solution().createList();
	Solution().showList(L1);
	cout<<Solution().hasCycle(L1);
	Solution().createCycle(L1, 0);
	cout << endl;
	cout << Solution().hasCycle(L1);
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
//给定一个链表，判断链表中是否有环。
//
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。
//
//
//
//示例 1：
//
//输入：head = [3, 2, 0, -4], pos = 1
//输出：true
//解释：链表中有一个环，其尾部连接到第二个节点。
//
//
//示例 2：
//
//输入：head = [1, 2], pos = 0
//输出：true
//解释：链表中有一个环，其尾部连接到第一个节点。
//
//
//示例 3：
//
//输入：head = [1], pos = -1
//输出：false
//解释：链表中没有环。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/linked-list-cycle
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//不能讲判断相等的==写成=语句