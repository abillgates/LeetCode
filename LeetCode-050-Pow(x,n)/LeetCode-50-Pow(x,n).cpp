// LeetCode-50-Pow(x,n).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
class Solution {
public:
	double myPow1(double x, int n) {
		if (n == 0)
			return 1.0;
		long long N = n;
		if (N < 0) {
			x = 1 / x;
			N = -N;
		}
		double result = x;
		for (int i = 0; i < N-1; i++) {
			result = result * x;
		}
		return result;
	}
	double myPow2(double x, int n) {
		if (n == 0)
			return 1.0;
		long long N = n;
		if (N < 0) {
			x = 1 / x;
			N = -N;
		}
		return fastPow(x, N);
	}
	double fastPow(double x, long long int n) {
		if (n == 0)
			return 1.0;
		if (n == 1)
			return x;
		double m = fastPow(x,n / 2);
		if (n % 2 == 0) {
			return m * m;
		}
		else
		{
			return m * m*x;
		}
	}
	double myPow(double x, int n) {
		long long N = n;
		if (N < 0) {
			x = 1 / x;
			N = -N;
		}
		double ans=1;
		double current = x;
		for (long long int i = N; i; i = i / 2) {
			if (i % 2 == 1) {
				ans = ans * current;
			}
			current = current * current;
		}
		return ans;
	}
	
};
int main()
{
	double x = 2;
	int n = -2;
	cout << Solution().myPow(x, n);
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
//实现 pow(x, n) ，即计算 x 的 n 次幂函数。
//
//示例 1:
//
//输入: 2.00000, 10
//	输出 : 1024.00000
//	示例 2 :
//
//	输入 : 2.10000, 3
//	输出 : 9.26100
//	示例 3 :
//
//	输入 : 2.00000, -2
//	输出 : 0.25000
//	解释 : 2 - 2 = 1 / 22 = 1 / 4 = 0.25
//	说明 :
//
//	-100.0 < x  < 100.0
//	n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/powx-n
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。