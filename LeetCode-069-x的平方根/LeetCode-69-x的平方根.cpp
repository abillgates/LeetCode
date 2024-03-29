// LeetCode-69-x的平方根.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
class Solution {
public:
	int mySqrt1(int x) {
		for (long long i = 0;; i++) {
			if (i*i == x) {
				return i;
			}
			else if(i*i>x)
			{
				return i - 1;
			}
		}
	}
	int mySqrt(int x) {
		if (x <= 1)
			return x;
		long long left = 0, right = x / 2 + 1;
		while (left<right)
		{
			long long middle = (left + right) / 2;
			long long temp = middle * middle;
			if (temp == x)
				return middle;
			else if (temp < x)
				left = middle + 1;
			else
			{
				right = middle - 1;
			}
		}
		return right;
	}
};
int main()
{
	int n = 15;
	cout << Solution().mySqrt(n);
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
//实现 int sqrt(int x) 函数。
//
//计算并返回 x 的平方根，其中 x 是非负整数。
//
//由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
//
//示例 1:
//
//输入: 4
//	输出 : 2
//	示例 2 :
//
//	输入 : 8
//	输出 : 2
//	说明 : 8 的平方根是 2.82842...,
//	由于返回类型是整数，小数部分将被舍去。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/sqrtx
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。