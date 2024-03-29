// LeetCode-30-串联所有单词的子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring1(string s, vector<string>& words) {
		vector<int> result = {};
		if (s.length() == 0 || words.size() == 0)
			return result;
		int WindowSize = words.size()*words[0].size();
		if (WindowSize > s.size())
			return result;
		for (int i = 0; i <= s.size() - WindowSize; i++) {
			if (isMatch1(s.substr(i, WindowSize), words))
				result.push_back(i);
		}
		return result;
	}
	bool isMatch1(string s,const vector<string>& words) { //Timeout
		int length = words[0].length();
		int n = words.size();
		vector<string> compare;
		for (int i = 0; i <s.size(); i = i + length)
			compare.push_back(s.substr(i, length));
		vector<bool>flag(words.size());
		for (auto i : flag)
			i = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (words[i] == compare[j]) {
					if (!flag[j]) {
						flag[j] = true;
						break;//防止匹配多次
					}
				}					
			}
		}
		for (bool i : flag) {
			if (!i)
				return false;
		}
		return true;		
	}
	bool isMatch2(string s, const vector<string>& words) { //Timeout
		int length = words[0].length();
		int n = words.size();
		vector<string> compare;
		for (int i = 0; i < s.size(); i = i + length)
			compare.push_back(s.substr(i, length));
		vector<bool>flag(words.size());
		for (auto i : flag)
			i = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < compare.size(); j++) {
				if (words[i] == compare[j]) {
					compare.erase(compare.begin() + j);
					break;
				}
			}
		}
		if (compare.empty())
			return true;
		else
			return false;
	}
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result = {};
		if (s.size() == 0 || words.size() == 0)
			return result;
		int n = words.size();
		int wordLength = words[0].length();
		unordered_map<string, int> wordCount;
		for (string i : words)
			++wordCount[i];
		for (int i = 0; i <= (int)s.length() - n * wordLength; i++) {
			unordered_map<string, int> compare;
			int j = 0;
			for (; j < n; j++) {
				string tmpStr = s.substr(i + j * wordLength, wordLength);
				if (!wordCount.count(tmpStr))
					break;
				else
				{
					++compare[tmpStr];
					if (compare[tmpStr] > wordCount[tmpStr])
						break;
				}
			}
			if (j == n)
				result.push_back(i);
		}
		return result;
	}
	
};
int main()
{
	/*vector<string> words = { "foo","bar" };
	string s = "barfoothefoobarman";*/
	vector<string> words = {  };
	string s = "";
	vector<int> result = Solution().findSubstring(s, words);
	for (int i : result)
		cout << i << " ";
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
