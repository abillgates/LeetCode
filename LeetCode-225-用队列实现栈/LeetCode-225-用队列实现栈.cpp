// LeetCode-225-用队列实现栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<deque>
#include<queue>
using namespace std;
//class MyStack {
//public:
//	/** Initialize your data structure here. */
//	MyStack() {
//
//	}
//
//	/** Push element x onto stack. */
//	void push(int x) {
//		Qstack.push_back(x);
//	}
//
//	/** Removes the element on top of the stack and returns that element. */
//	int pop() {
//		int x = Qstack.back();
//		Qstack.pop_back();
//		return x;
//	}
//
//	/** Get the top element. */
//	int top() {
//		return Qstack.back();
//	}
//
//	/** Returns whether the stack is empty. */
//	bool empty() {
//		return Qstack.empty();
//	}
//private:
//	deque<int> Qstack;
//};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MyStack0 {
public:
	MyStack0() {
		//nothing to do
	}

	/** Push element x onto stack. */
	void push(int x) {
		Qstack.push(x);
		for (int i = 0; i < Qstack.size() - 1; i++) {
			Qstack.push(Qstack.front());
			Qstack.pop();
		}
	}
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int x = Qstack.front();
		Qstack.pop();
		return x;
	}

	/** Get the top element. */
	int top() {
		return Qstack.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return Qstack.empty();
	}
private:
	queue<int> Qstack;
};
class MyStack1 {
public:
	MyStack1() {
		//nothing to do
	}
	/** Push element x onto stack. */
	void push(int x) {
		Qstack2.push(x);
		while (!Qstack1.empty())
		{
			Qstack2.push(Qstack1.front());
			Qstack1.pop();
		}
		swap(Qstack1, Qstack2);
	}
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int x = Qstack1.front();
		Qstack1.pop();
		return x;
	}

	/** Get the top element. */
	int top() {
		return Qstack1.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return Qstack1.empty();
	}
private:
	queue<int> Qstack1;
	queue<int> Qstack2;
};
class MyStack {
public:
	MyStack() {
		//nothing to do
	}
	/** Push element x onto stack. */
	void push(int x) {
		Qstack1.push(x);		
	}
	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		while (Qstack1.size()>1)
		{
			Qstack2.push(Qstack1.front());
			Qstack1.pop();
		}
		int x = Qstack1.front();
		Qstack1.pop();
		swap(Qstack1, Qstack2);
		return x;
	}

	/** Get the top element. */
	int top() {
		return Qstack1.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return Qstack1.empty();
	}
private:
	queue<int> Qstack1;
	queue<int> Qstack2;
};
int main()
{
	MyStack stack;
	stack.push(1);
	stack.push(2);
	int param_2 = stack.pop();
	int param_3 = stack.top();
	bool param_4 = stack.empty();
	cout << param_2 << param_3 << param_4;
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
//使用队列实现栈的下列操作：
//
//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空
//注意 :
//
//你只能使用队列的基本操作-- 也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
//你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
//你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/implement-stack-using-queues
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。