// LeetCode-383-赎金信.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		map<char, int> dict;
		for (int i = 0; i < magazine.size(); i++) {
			dict[magazine[i]]++;
		}
		for (int i = 0; i < ransomNote.size(); i++) {
			if (dict.count(ransomNote[i]) == 0) {
				return false;
			}
			else {
				if (!dict[ransomNote[i]])
					return false;
				dict[ransomNote[i]]--;
			}
		}
		return true;
	}
};
int main()
{
	cout << Solution().canConstruct("aa", "aab");
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
//给定一个赎金信(ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。
//
//(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)
//
//注意：
//
//你可以假设两个字符串均只含有小写字母。
//
//canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/ransom-note
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。