// LeetCode-67-二进制求和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		int n1 = a.length() - 1;
		int n2 = b.length() - 1;
		int carry = 0;
		string result;
		while (n1>=0||n2>=0)
		{
			if (n1 >= 0) {
				carry = carry + a[n1]-'0';
			}
			if (n2 >= 0) {
				carry = carry + b[n2]-'0';
			}
			result.push_back(carry % 2 + '0');
			carry = carry / 2;
			n1--;
			n2--;
		}
		if (carry == 1)
			result.push_back('1');
		reverse(result.begin(), result.end());
		return result;
	}
};
int main()
{
	string a = "1010";
	string b = "1011";
	cout << Solution().addBinary(a, b);
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
//给定两个二进制字符串，返回他们的和（用二进制表示）。
//
//输入为非空字符串且只包含数字 1 和 0。
//
//示例 1 :
//
//输入: a = "11", b = "1"
//	输出 : "100"
//	示例 2 :
//
//	输入 : a = "1010", b = "1011"
//	输出 : "10101"
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/add-binary
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。