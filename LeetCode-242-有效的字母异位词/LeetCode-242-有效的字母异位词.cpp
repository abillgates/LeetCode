// LeetCode-242-有效的字母异位词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
	bool isAnagram(string s, string t) {
		map<char, int> m1, m2;
		if (s.length() != t.length()) {
			return false;
		}
		for (int i = 0; i < s.length(); i++) {
			m1[s[i]]++;
			m2[t[i]]++;
		}
		return m1 == m2;
	}
};
int main()
{
	string s = "anagram";
	string t = "nagaram";
	cout << Solution().isAnagram(s, t);
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
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//
//示例 1 :
//
//输入: s = "anagram", t = "nagaram"
//	输出 : true
//	示例 2 :
//
//	输入 : s = "rat", t = "car"
//	输出 : false
//	说明 :
//	你可以假设字符串只包含小写字母。
//
//	进阶 :
//	如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
//
//		来源：力扣（LeetCode）
//		链接：https ://leetcode-cn.com/problems/valid-anagram
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。