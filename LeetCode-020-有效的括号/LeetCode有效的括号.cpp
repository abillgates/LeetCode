// LeetCode有效的括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<map>
#include<stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		map<char, char> match;
		stack<char> storage;
		match.insert(pair<char, char>(')', '('));
		match.insert(pair<char, char>('}', '{'));
		match.insert(pair<char, char>(']', '['));
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				storage.push(s[i]);
			}
			else if(s[i]==')'||s[i]=='}'||s[i]==']')
			{
				if (!storage.empty()&&storage.top() ==match[s[i]])
					storage.pop();
				else
					return false;
			}
		}
		if (storage.empty())
			return true;
		else
			return false;
	}
};
int main()
{
	string s = "()[]{}";
	cout << Solution().isValid(s);
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
