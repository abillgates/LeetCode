// LeetCode-227-基本计算器II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
	int calculate(string s) {
		long res = 0, num = 0, n = s.length();
		char op = '+';
		stack<int> st;
		for (int i = 0; i < n; i++) {
			if (s[i] >= '0'&&s[i] <= '9') {
				num = num * 10 + s[i] - '0';
			}
			if ((s[i] < '0'&&s[i] != ' ') || i == n - 1) {
				switch (op)
				{
				case '+':st.push(num); break;
				case'-':st.push(-num); break;
				case'*':num = num * st.top();
					st.pop();
					st.push(num);
					break;
				case'/':num = st.top() / num;
					st.pop();
					st.push(num);
					break;
				default:
					break;
				}
				num = 0;
				op = s[i];
			}
		}
		while (!st.empty())
		{
			res += st.top();
			st.pop();
		}
		return res;
	}
};
int main()
{
	string s = "3+5/2";
	cout << Solution().calculate(s);
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
//实现一个基本的计算器来计算一个简单的字符串表达式的值。
//
//字符串表达式仅包含非负整数， + ， - ， * ， / 四种运算符和空格  。 整数除法仅保留整数部分。
//
//示例 1 :
//
//输入: "3+2*2"
//	输出 : 7
//	示例 2 :
//
//	输入 : " 3/2 "
//	输出 : 1
//	示例 3 :
//
//	输入 : " 3+5 / 2 "
//	输出 : 5
//	说明：
//
//	你可以假设所给定的表达式都是有效的。
//	请不要使用内置的库函数 eval
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/basic-calculator-ii
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。