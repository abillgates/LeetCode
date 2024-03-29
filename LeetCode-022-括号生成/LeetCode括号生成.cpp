// LeetCode括号生成.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> generateResult = {};
		char* str = new char[2 * n+1];
		str[2*n] ='\0';
		Tracebackgenerate(str, generateResult, 2*n, 0);
		return generateResult;
	}
	void Tracebackgenerate(char *str, vector<string>& result, int max, int pos) {
		if (pos == max) {
			if (isValid(str)){								
				result.push_back(str);
				/*for (auto i : result) {
					cout << i << endl;
				}*/
			}	
			return;
		}
		else
		{
			str[pos]='(';
			Tracebackgenerate(str, result, max, pos + 1);
			str[pos] =')';
			Tracebackgenerate(str, result, max, pos + 1);
		}
	}
	bool isValid(char* str) {
		string s = str;		
		int count=0;		
		for (int i = 0;i<s.length(); i++) {
			if (s[i] == '(') {
				count++;				
			}
			else if(s[i]==')'){
				if (count)
					count--;
				else
					return false;
			}
		}		
		return count == 0;
	}
	vector<string> generateParenthesis1(int n) {
		vector<string> generateResult = {};
		//char* str = new char[2 * n + 1];
		//str[2 * n] = '\0';
		//Tracebackgenerate(str, generateResult, 2*n,0);
		Tracebackgenerate1("", generateResult, 0, 0, n);
		return generateResult;
	}
	void Tracebackgenerate1(string s, vector<string>& result, int left, int right,int max) {
		if (left == max && right == max) {
			result.push_back(s);
			return;
		}
		if(left<max)
		{
			Tracebackgenerate1(s + '(', result, left + 1, right,max);
		}
		if (right < left) {											//不能使用else if											
			Tracebackgenerate1(s + ')', result, left, right + 1, max);
		}
	}
};
int main()
{
	auto s = Solution().generateParenthesis1(4);
	//cout << s.size();
	for (auto i : s) {
		cout << i << endl;
	}
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
