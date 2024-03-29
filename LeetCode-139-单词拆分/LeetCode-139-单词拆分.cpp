// LeetCode-139-单词拆分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<set>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
	enum status
	{
		UNKNOWN,
		YES,
		NO
	};
	bool wordBreak0(string s, vector<string>& wordDict) {
		int m = wordDict.size();
		int n = s.length();
		set<string> word;
		vector<bool> dp(n + 1, false);
		dp[0] = true;
		for (int i = 0; i < m; i++) {
			word.insert(wordDict[i]);
		}
		//copy(wordDict.begin(), wordDict.end(), word.begin());
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				string temp = s.substr(j, i - j);
				/*cout << temp << endl;*/
				if (dp[j] && word.count(temp) != 0) {
					dp[i] = true;
					break;
				}
			}
		}
		/*for (bool i : dp) {
			cout << i << " ";
		}*/
		return dp[n];
	}
	bool wordBreak1(string s, vector<string>& wordDict) {
		set<string> word;
		int l = s.length();
		for (int i = 0; i < wordDict.size(); i++) {
			word.insert(wordDict[i]);
		}
		return traceBackWord1(word, s, 0, l);
	}
	bool traceBackWord1(set<string> word, string s, int begin, int end) {
		if (begin == s.length()) {
			return true;
		}
		for (int i = begin + 1; i <= end; i++) {
			string temp = s.substr(begin, i - begin);
			if (word.count(temp) && traceBackWord1(word, s, i, end)) {
				return true;
			}
		}
		return false;
	}
	bool wordBreak2(string s, vector<string>& wordDict) {
		vector<status> memo(s.length(), UNKNOWN);
		set<string> word;
		for (int i = 0; i < wordDict.size(); i++) {
			word.insert(wordDict[i]);
		}
		status res= tracebackword2(word, s, 0, s.length(), memo);
		if (res == YES) {
			return true;
		}
		return false ;
	}
	status tracebackword2(set<string> word, string s, int begin, int end,vector<status> memo) {
		if (begin == s.length()) {
			return YES;
		}
		if (memo[begin] != UNKNOWN) {
			return memo[begin];
		}
		for (int i = begin + 1; i <= end; i++) {
			string temp = s.substr(begin, i - begin);
			if (word.count(temp) && tracebackword2(word, s, i, end, memo)==YES) {
				memo[begin]=YES;
				return memo[begin];
			}
		}
		memo[begin] = NO;
		return memo[begin];
	}
	bool wordBreak(string s, vector<string>& wordDict) {
		int m = s.length();
		set<string> word;
		vector<bool> visited(m, false);
		queue<int> q;
		for (int i = 0; i < wordDict.size(); i++) {
			word.insert(wordDict[i]);
		}
		q.push(0);
		while (!q.empty()) {
			int start = q.front();
			q.pop();
			if (!visited[start]) {
			for (int i = start + 1; i <= m; i++) {		
					string temp = s.substr(start, i - start);
					/*cout << temp << endl;*/
					if (word.count(temp)) {
						q.push(i);
						/*cout << i << endl;*/
						if (i == m) {
							return true;
						}
					}
				}	
			}
			visited[start] = true;
		}
		return false;
	}
};
int main()
{
	string s = "leetcode";
	vector<string> wordDict{
		{"leet"},
		{"code"}
	};
	cout<<Solution().wordBreak(s, wordDict);
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
//reference
//Function: dp[i] = (dp[i - j] + str[j:i] in dict) for j in range(i), 
//到字符i能否拆分取决于每一个以i结尾的str[j - i]字符 是否在字典里并且j字符之前的字符串可以拆分
//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//
//说明：
//
//拆分时可以重复使用字典中的单词。
//你可以假设字典中没有重复的单词。
//示例 1：
//
//输入 : s = "leetcode", wordDict = ["leet", "code"]
//	输出 : true
//	解释 : 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
//	示例 2：
//
//	输入 : s = "applepenapple", wordDict = ["apple", "pen"]
//	输出 : true
//	解释 : 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//	注意你可以重复使用字典中的单词。
//	示例 3：
//
//	输入 : s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//	输出 : false
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/word-break
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。