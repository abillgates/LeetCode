// ConsoleApplication4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
	map<string, string> keyboard{ {"2","abc"},{"3","def"},{"4","ghi"},{"5","jkl"},{"6","mno"},{"7","pqrs"},{"8","tuv"},{"9","wxyz"} };
	vector<string> result = {};
	vector<string> letterCombinations(string digits) {	
		if (digits.length() == 0) {
			return result;
		}
		else
			Traceback("", digits);
		return result;
	}
	void Traceback(string com, string digits) {
		if (digits.length() == 0) {
			result.push_back(com);
		}
		else
		{
			string number = digits.substr(0, 1);
			string letter = keyboard[number];
			for (int i = 0; i < letter.length(); i++) {
				com.push_back(letter[i]);
				Traceback(com, digits.substr(1));
				com.pop_back();
			}
		}
	}
	vector<string> letterCombinations1(string digits) {

		if (digits == "")
		{
			return vector<string>();
		}
		char digit_c_array[8][4] = {
			{'a','b','c'},
			{'d','e','f'},
			{'g','h','i'},
			{'j','k','l'},
			{'m','n','o'},
			{'p','q','r','s'},
			{'t','u','v'},
			{'w','x','y','z'},
		};

		vector<string> res(1, "");

		for (int i = 0; i < digits.size(); ++i)
		{
			vector<string> temp;

			int digit = digits[i] - '2';

			for (int j = 0; j < res.size(); ++j)
			{

				for (int k = 0; k <= 2; ++k)
				{
					temp.push_back(res[j] + digit_c_array[digit][k]);
				}
				if (digit == 5 || digit == 7)
				{
					temp.push_back(res[j] + digit_c_array[digit][3]);
				}
			}
			res = temp;
			cout << res.size();
			for (auto i : res) {
				cout << i << "--";
			}
		}
		return res;
	}

};
int main() {
	vector<string> result;
	result=Solution().letterCombinations1("234");
	for (auto i : result)
		cout << i << " ";
	return 0;
}
