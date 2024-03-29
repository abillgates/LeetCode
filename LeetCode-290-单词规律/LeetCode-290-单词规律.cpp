// LeetCode-290-单词规律.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		vector<string> words;
		map<char, string> recordp;
		set<string> records;
		for (int i = 0; i < str.length(); i++) {
			int temp = i;
			while (i<str.length()&&str[i] != ' ')
				i++;
			words.push_back(str.substr(temp, i - temp ));
			//cout << str.substr(temp, i - temp) << endl;
		}
		if (pattern.length() != words.size()) {
			return false;
		}
		for (int i = 0; i < pattern.length(); i++) {
			if (recordp.count(pattern[i]) == 0) {
				if (records.count(words[i])==0) {
					recordp.insert({ pattern[i], words[i] });
					records.insert(words[i]);
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (recordp[pattern[i]] != words[i]) {
					return false;
				}
			}
		}
		return true;
	}
};
int main()
{
	string str = "dog cat cat dog";
	string pattern = "abba";
	cout << Solution().wordPattern(pattern, str);
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
//给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
//
//这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
//
//示例1 :
//
//输入: pattern = "abba", str = "dog cat cat dog"
//	输出 : true
//	示例 2 :
//
//	输入 : pattern = "abba", str = "dog cat cat fish"
//	输出 : false
//	示例 3 :
//
//	输入 : pattern = "aaaa", str = "dog cat cat dog"
//	输出 : false
//	示例 4 :
//
//	输入 : pattern = "abba", str = "dog dog dog dog"
//	输出 : false
//	说明 :
//	你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。 
//  paper
//  title
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/word-pattern
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。