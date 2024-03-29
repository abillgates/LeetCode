// LeetCode-434-字符串中的单词数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
	int countSegments(string s) {
		int n = s.length();
		int res = 0;
		int i = 0;
		while (i+1<n)
		{
			if (s[i + 1] == ' '&&s[i] != ' ')
				res++;
			i++;
		}
		if (s[n - 1] != ' ')
			res++;
		return res;
	}
};
int main()
{
	string s = "Hello, my name is John";
	cout << Solution().countSegments(" ");
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
//统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
//
//请注意，你可以假定字符串里不包括任何不可打印的字符。
//
//示例 :
//
//输入: "Hello, my name is John"
//	输出 : 5
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/number-of-segments-in-a-string
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。