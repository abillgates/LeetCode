// LeetCode-29-两数相除.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		long int result = 0;
		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX;
		/*else if (dividend == INT_MIN && divisor == 1)
			return INT_MIN;
		else if (dividend == INT_MAX && divisor == 1)
			return INT_MAX;
		else if (dividend == INT_MAX && divisor == -1)
			return INT_MIN + 1;*/
		int notation=1;
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor>0))
			notation = -1;
		long int div1=dividend;
		div1 = div1 > 0 ? div1 : -div1;
		long int div2 = divisor;
		div2=div2 > 0 ? div2 : -div2;
		while (div1 >= div2)
		{
			long int tempdivisor = div2;int tempresult = 1;//reset
			while (div1 >= (tempdivisor << 1))
			{
				tempdivisor=tempdivisor << 1;
				tempresult= tempresult << 1;
			}
			result = result + tempresult;
			div1 = div1 - tempdivisor;
		}
		return notation == 1 ? result : -result;
	}
};
int main()
{
	cout << Solution().divide(INT_MIN, -1);
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
//   reference bit operation