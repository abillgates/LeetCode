// LeetCode-091-解码方法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	int numDecodings(string s) {
		int n = s.length();
		if (!n) {
			return 0;
		}
		vector<int> res(n);
		res[n-1] = (s[n-1] == '0' )? 0 : 1;
		for (int i = n-2; i>=0; i--) {
			if (s[i]=='1') {
				if (s[i + 1] != '0') {
					res[i] = res[i + 1] + (i + 2 > n - 1 ? 1 : res[i + 2]);
				}
				else {
					res[i] = i + 2 > n - 1 ? 1 : res[i + 2];
				}
			}
			else if (s[i]=='2')
			{
				if (s[i + 1] > '0'&&s[i + 1] < '7') {
					res[i] = res[i + 1] + (i + 2 > n - 1 ? 1 : res[i + 2]);
				}
				else if (s[i + 1] == '0') {
					res[i] = i + 2 > n - 1 ? 1 : res[i + 2];
				}
				else {
					res[i] = res[i + 1];
				}
			}
			else {
				if (s[i] == '0') {
					res[i] = 0;
				}
				else {
					res[i] = res[i + 1];
				}
			}
		}
		return res[0];
	}
};
int main()
{
	string s = "12";
	cout << Solution().numDecodings(s);
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
//一条包含字母 A - Z 的消息通过以下方式进行了编码：
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//给定一个只包含数字的非空字符串，请计算解码方法的总数。
//
//示例 1:
//
//输入: "12"
//	输出 : 2
//	解释 : 它可以解码为 "AB"（1 2）或者 "L"（12）。
//	示例 2 :
//
//输入: "226"
//	输出 : 3
//	解释 : 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/decode-ways
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。