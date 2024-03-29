// LeetCode-093-复原IP地址.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	/*vector<string> restoreIpAddresses(string s) {
		int m = s.length();
		vector<string> res;
		traceback(res, s, "", 0, 0);
		return res;
	}
	void traceback(vector<string> res, string s, string build,int sec, int start) {
		if (sec == 3) {
			string temp = s.substr(start);
			if (temp.length()>3) {
				return;
			}
			else if (temp.length()== 3) {				
				if (!isValid(temp)) {
					return;
				}
				build += temp;
				res.push_back(build);
				return;
			}
			else
			{
				build += temp;
				res.push_back(temp);
				return;
			}
		}
		for (int i = start+1; i <=start+3; i++) {
			if (i > s.length()) {
				return;
			}
			string temp = s.substr(start, i - start);
			cout << temp << endl;
			if (isValid(temp)) {
				build = build + temp + '.';
				sec++;
				cout << "累计" << sec << endl;
				traceback(res, s, build, sec, i);
			}
			else {
				return;
			}
		}
	}
	bool isValid(string s) {
		if (s.length() <= 2) {
			return true;
		}
		for (int i = 0; i < 3; i++) {
			if (s[0] > '2') {
				return false;
			}
			else if (s[0] == '2'&&s[1] > '5') {
				return false;
			}
			else if (s[0] == '2'&&s[1] == '5'&&s[2] > '5') {
				return false;
			}
		}
		return true;
	}*/
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		traceback(s, 4, "", res);
		return res;
	}
	void traceback(string s, int segment, string output, vector<string>& res) {
		if (segment == 0) {	
			if (s.empty()) {
				res.push_back(output);
			}
			/*cout << "s.size()" << s.size() << "output" << output << endl;*/
			return;
		}
		for (int i = 1; i <= 3; i++) {
			if (i <= s.size()) {
				string temp = s.substr(0, i);
				if (isVaild(temp)) {
					if (segment == 1) {
						traceback(s.substr(i), segment - 1, output + temp, res);
					}
					else {
						traceback(s.substr(i), segment - 1, output + temp + '.', res);
					}
				}
			}
		}
	}
	bool isVaild(string s) {
		if ((s.length() > 3) || (s.length() >= 2 && s[0] == '0')) {
			return false;
		}
		int res = atoi(s.c_str());
		if (res >= 0 && res <= 255) {
			return true;
		}
		return false;
	}
};
int main()
{
	string s = "25525511135";
	vector<string> result = Solution().restoreIpAddresses(s);
	for (string i : result) {
		cout << i << endl;
	}
    //std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
// reference https://www.cnblogs.com/grandyang/p/4305572.html
// 修改数组需要传递引用
// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
//给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
//
//示例 :
//
//  输入: "25525511135"
//	输出 : ["255.255.11.135", "255.255.111.35"]
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/restore-ip-addresses
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。