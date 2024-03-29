// LeetCode-42-接雨水.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int min(int a, int b) {
		if (a <= b)
			return a;
		else
			return b;
	}
	int max(int a, int b) {
		if (a >= b)
			return a;
		else
			return b;
	}
	int trap1(vector<int>& height) {
		int n = height.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int maxleft = height[i];
			int maxright = height[i];
			for (int j = i; j > 0; j--) {
				maxleft = max(maxleft,height[j]);
			}
			for (int k = i; k < n; k++) {
				maxright = max(maxright,height[k]);
			}
			ans = ans + min(maxleft, maxright) - height[i];
		}
		return ans;
	}
	int trap2(vector<int>& height) {
		int n = height.size();
		int ans = 0;
		vector<int> max_left(n), max_right(n);
		max_left[0] = height[0];
		for (int i = 1; i < n; i++) {
			max_left[i] = max(height[i], max_left[i - 1]);
		}
		max_right[n - 1] = height[n - 1];
		for (int j = n - 2; j > 0; j--) {
			max_right[j] = max(height[j], max_right[j + 1]);
		}
		for (int i = 0; i < n; i++) {
			ans = ans + min(max_left[i], max_right[i]) - height[i];
		}
		return ans;
	}
	int trap3(const vector<int>& height) {
		int n = height.size();
		int ans = 0;
		stack<int> st;
		int current = 0;
		while (current < n) {
			while (!st.empty()&&height[current]>height[st.top()])
			{
				int top = st.top();
				st.pop();
				if (st.empty())
					break;
				int distance = current - st.top() - 1;
				ans = ans + distance * (min(height[current], height[st.top()])-height[top]);
			}
			st.push(current);
			current++;
		}
		return ans;
	}
	int trap(const vector<int>& height) {
		if (height.size() == 0)
			return 0;
		int left = 0, right = height.size() - 1;
		int max_left = height[left],max_right = height[right];
		int ans = 0;
		while (left<right)
		{
			if (height[left] < height[right]) {
				if (height[left] > max_left)
					max_left = height[left];
				else
					ans = ans + max_left - height[left];
				left++;
			}
			else
			{
				if (height[right] > max_right)
					max_right = height[right];
				else
					ans = ans + max_right - height[right];
				right--;
			}
		}
		return ans;
	}
};
int main()
{
	vector<int> num = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << Solution().trap(num);
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
//   reference the official