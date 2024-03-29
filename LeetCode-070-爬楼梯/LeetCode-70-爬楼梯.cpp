// LeetCode-70-爬楼梯.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int climbStairs0(int n) {
		if (n == 1)
			return 1;
		else if (n == 2)
			return 2;
		else
			return climbStairs(n - 1) + climbStairs(n - 2);
	}
	int climbStairs1(int n) {
		vector<long long> result{ 1,2 };
		int count = result.size();
		if (count >= n)
			return result[n - 1];
		else
		{
			while (count<n)
			{
				result.push_back(result[count - 1] + result[count - 2]);
				count = result.size();
			}
			
		}
		return result[n - 1];
	}
	int climbStairs(int n) {
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		long long pre = 1, last = 2;
		long long result = 0;
		for (int i = 3; i <= n; i++) {
			result = pre + last;
			pre = last;
			last = result;
		}
		return result;
	}

};
int main()
{
	cout << Solution().climbStairs(100);
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
//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//
//注意：给定 n 是一个正整数。
//
//示例 1：
//
//输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 阶 + 1 阶
//2.  2 阶
//示例 2：
//
//输入： 3
//输出： 3
//解释： 有三种方法可以爬到楼顶。
//1.  1 阶 + 1 阶 + 1 阶
//2.  1 阶 + 2 阶
//3.  2 阶 + 1 阶
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/climbing-stairs
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。