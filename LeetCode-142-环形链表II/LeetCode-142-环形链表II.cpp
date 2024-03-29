// LeetCode-142-环形链表II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
			cout << p->val << "(" << p << ")";
			if (p->next) {
				cout << "->";
			}
		}
		cout << endl;
	}
	ListNode *createList() {
		ListNode head(0);
		ListNode* p = &head;
		int n;
		while (cin>>n)
		{
			p->next = new ListNode(n);
			p=p->next;
			if (cin.get() == '\n') {
				break;
			}
		}
		return head.next;
	}
	void createCycle(ListNode* &head,int pos) {
		if (pos == -1) {
			return;
		}
		ListNode* last=head;
		ListNode* pre=head;
		while (pos--)
		{
			pre = pre->next;
		}
		while (last->next)
		{
			last = last->next;
		}
		last->next = pre;
	}
	ListNode *detectCycle0(ListNode *head) {
		set<ListNode*> detect;
		ListNode* p = head;
		while (p)
		{
			if (detect.insert(p).second == false) {
				return p;
			}
			p = p->next;
		}
		return nullptr;
	}
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode* slow = head, *fast = head;//快慢指向同一个位置
		ListNode* meet = nullptr;
		ListNode* begin = head;
		if (!fast) {
			return nullptr;
		}
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				meet = fast;
				break;
			}
		}
		if (!meet) {
			return nullptr;
		}
		else
		{
			while (begin!=meet)
			{
				begin = begin->next;
				meet = meet->next;
			}
		}
		return meet;
	}
};
int main()
{
	Solution::ListNode* L1 = Solution().createList();
	Solution().showList(L1);
	cout<<Solution().detectCycle(L1)<<endl;
	Solution().createCycle(L1,1);
	cout<<Solution().detectCycle(L1);
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
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。
//
//说明：不允许修改给定的链表。
//
//
//
//示例 1：
//
//输入：head = [3, 2, 0, -4], pos = 1
//输出：tail connects to node index 1
//解释：链表中有一个环，其尾部连接到第二个节点。
//
//
//示例 2：
//
//输入：head = [1, 2], pos = 0
//输出：tail connects to node index 0
//解释：链表中有一个环，其尾部连接到第一个节点。
//
//
//示例 3：
//
//输入：head = [1], pos = -1
//输出：no cycle
//解释：链表中没有环。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/linked-list-cycle-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。