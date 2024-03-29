// LeetCode-345-反转字符串中的元音字母.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<set>
using namespace std;
class Solution {
public:
	string reverseVowels(string s) {
		set<char> t{ 'a','e','i','o','u','A','E','I','O','U' };
		int n = s.length();
		if (!n)return s;
		int i = 0, j = n - 1;
		while (true)
		{
			while (t.count(s[i]) == 0) {
				i++;
				if (i == n)
					return s;
			}
			while (t.count(s[j]) == 0)j--;
			if (i < j)
				swap(s[i], s[j]);
			else
				break;
			i++;
			j--;
		}
		return s;
	}
};
int main()
{
	string s = " ";
	cout << Solution().reverseVowels(s);
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
//编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
//
//示例 1:
//
//输入: "hello"
//	输出 : "holle"
//	示例 2 :
//
//	输入 : "leetcode"
//	输出 : "leotcede"
//	说明 :
//	元音字母不包含字母"y"。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/reverse-vowels-of-a-string
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。