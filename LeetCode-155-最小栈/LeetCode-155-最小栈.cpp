// LeetCode-155-最小栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}
	void push(int x) {
		if (!minStack.empty()) {
			int min = getMin();
			if (x < min) {
				min = x;
			}
			minStack.push_back({ x, min });
		}
		else
		{
			minStack.push_back({ x,x });
		}
	}
	void pop() {
		if (!minStack.empty()) {
			minStack.pop_back();
		}
		else
		{
			cout << "the stack already empty";
		}
	}
	int top() {
		return minStack[getSize() - 1].data;
	}
	int getMin() {
		return minStack[getSize() - 1].minidata;
	}
	int getSize() {
		return minStack.size();
	}
private:
	struct dataNode
	{
		int data;
		int minidata;
	};
	vector<dataNode> minStack;
};
int main()
{
	MinStack mystack;
	mystack.push(-2);
	mystack.push(0);
	mystack.push(-3);
	cout << mystack.getMin()<<endl;
	mystack.pop();
	cout << mystack.top()<<endl;
	cout << mystack.getMin() << endl;
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
//设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
//
//push(x) --将元素 x 推入栈中。
//pop() --删除栈顶的元素。
//top() --获取栈顶元素。
//getMin() --检索栈中的最小元素。
//示例 :
//
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   -- > 返回 - 3.
//minStack.pop();
//minStack.top();      -- > 返回 0.
//minStack.getMin();   -- > 返回 - 2.
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/min-stack
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。