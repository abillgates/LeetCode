// LeetCode-32-最长有效括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int longestValidParentheses1(string s) {//TimeOut
		int max = 0;
		for (int len = 2; len <=s.size(); len++) {
			for(int i=0;i<=s.size()-len;i++)
				if (isMatchParentheses(s.substr(i, len))) {
					max = len;
					break;
				}
		}
		return max;
	}
	bool isMatchParentheses(string s) {
		stack<char> Parentheses;	
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				Parentheses.push(s[i]);
			else {
				if (Parentheses.empty())
					return false;
				else {
					Parentheses.pop();
				}		
			}
		}
		if (Parentheses.empty())
			return true;
		else
			return false;
	}
	int longestValidParentheses2(string s) {
		int start=0;
		int leftCount = 0, rightCount = 0;
		int max = 0, temp = 0;
		for (int i = 0; i < s.size(); i++) {			
			if (s[i] == '(') {
				leftCount++;
			}					
			else if (s[i] == ')') {
				rightCount++;
			}	
			if (rightCount > leftCount) {
				rightCount = 0;
				leftCount = 0;
				start = i + 1;			
			}
			else if (rightCount == leftCount) {
				temp = i - start + 1;
				if (temp > max)
					max = temp;
			}				
		}
		leftCount = rightCount = 0;
		start = s.size() - 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			
			if (s[i] == ')')
				rightCount++;
			else if (s[i] == '(')
				leftCount++;
			if (leftCount > rightCount) {
				leftCount = 0;
				rightCount = 0;
				if (i - 1 >= 0)
					start = i - 1;
			}
			else if (leftCount == rightCount) {
				temp = start - i + 1;
				if (temp > max)
					max = temp;
			}
		}
		return max;	
	}
	int longestValidParentheses3(string s) {
		stack<int> Parentheses;
		int max = 0, temp = 0, bottom = -1;
		Parentheses.push(-1);
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				Parentheses.push(i);
			}
			else if (s[i] == ')') {
				Parentheses.pop();
				
				if (!Parentheses.empty()) {
					temp=i-Parentheses.top();
					
					if (temp > max)
						max = temp;
				}
				else {
					Parentheses.push(i);					
				}
			}
		}
		return max;
	}
	int longestValidParentheses(string s) {
		vector<int> dp(s.size());
		int max = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == ')') {
				if (s[i - 1] == '(')
					dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				else if (i - dp[i - 1] - 1>0&&s[i - dp[i - 1] - 1] == '(')
					dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
			}
		}
		for (int i : dp)
			max = i > max ? i : max;
		return max;
	}
};
int main()
{
	string s = "((())())(()))(()()(()(()))(()((((()))))))((()())()))()()(()(((((()()()())))()())(()()))((((((())))((()))()()))))(()))())))()))()())((()()))))(()(((((())))))()((()(()(())((((())(())((()()(()())))())(()(())()()))())(()()()))()(((()())(((()()())))(((()()()))(()()))()))()))))))())()()((()(())(()))()((()()()((())))()(((()())(()))())())))(((()))))())))()(())))()())))())()((()))((()))()))(((())((()()()(()((()((())))((()()))())(()()(()))))())((())))(()))()))))))()(()))())(()())))))(()))((())(()((())(((((()()()(()()())))(()())()((()(()()))(()(())((()((()))))))))(()(())()())()(()(()(()))()()()(()()())))(())(()((((()()))())))(())((()(())())))))())()()))(((())))())((()(()))(()()))((())(())))))(()(()((()((()()))))))(()()()(()()()(()(())()))()))(((()(())()())(()))())))(((()))())(()((()))(()((()()()(())()(()())()(())(()(()((((())()))(((()()(((()())(()()()(())()())())(()(()()((()))))()(()))))(((())))()()))(()))((()))))()()))))((((()(())()()()((()))((()))())())(()((()()())))))))()))(((()))))))(()())))(((()))((()))())))(((()(((())))())(()))))(((()(((((((((((((())(((()))((((())())()))())((((())(((())))())(((()))))()())()(())())(()))))()))()()()))(((((())()()((()))())(()))()()(()()))(())(()()))()))))(((())))))((()()(()()()()((())((((())())))))((((((()((()((())())(()((()))(()())())())(()(())(())(()((())((())))(())())))(()()())((((()))))((()(())(()(()())))))))))((()())()()))((()(((()((()))(((((()()()()()(()(()((()(()))(()(()((()()))))()(()()((((((()((()())()))((())()()(((((()(()))))()()((()())((()())()(())((()))()()(()))";
	cout << Solution().longestValidParentheses2(s);

	return 0;
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
//   reference