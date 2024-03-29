// LeetCode-205-同构字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
class Solution {
public:
	bool isIsomorphic0(string s, string t) {
		map<char, char> records;
		set<char> recordt;
		for (int i = 0; i < s.length(); i++) {
			if (records.count(s[i]) == 0) {
				if (recordt.count(t[i]) == 0) {
					records.insert({s[i], t[i]});
					recordt.insert(t[i]);
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (records[s[i]] != t[i]) {
					return false;
				}
			}
		}
		return true;
	}
	bool isIsomorphic(string s, string t) {
		int n = s.length();
		for (int i = 0; i < n; i++) {
			if (s.find(s[i]) != t.find(t[i])) {
				return false;
			}
		}
		return true;
	}
};
int main()
{
	string s = "paper";
	string t = "title";
	//cout << s.find(s[0]);
	cout << Solution().isIsomorphic(s, t);
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
//给定两个字符串 s 和 t，判断它们是否是同构的。
//
//如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
//
//所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
//
//示例 1:
//
//输入: s = "egg", t = "add"
//	输出 : true
//	示例 2 :
//
//	输入 : s = "foo", t = "bar"
//	输出 : false
//	示例 3 :
//
//	输入 : s = "paper", t = "title"
//	输出 : true
//	说明 :
//	你可以假设 s 和 t 具有相同的长度。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/isomorphic-strings
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。