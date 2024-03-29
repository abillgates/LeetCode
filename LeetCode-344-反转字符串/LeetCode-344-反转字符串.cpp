// LeetCode-344-反转字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	void reverseString(vector<char>& s) {
		int n = s.size();
		for (int i = 0; i < n/2; i++) {
			char temp;
			temp = s[i];
			s[i] = s[n - 1 - i];
			s[n - 1 - i] = temp;
		}
	}
};
int main()
{
	vector<char> s = { 'h','e','l','l','o' };
	Solution().reverseString(s);
	for (char i : s) {
		cout << i << " ";
	}
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
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
//
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//
//你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
//
//
//
//示例 1：
//
//输入：["h", "e", "l", "l", "o"]
//输出：["o", "l", "l", "e", "h"]
//示例 2：
//
//输入：["H", "a", "n", "n", "a", "h"]
//输出：["h", "a", "n", "n", "a", "H"]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/reverse-string
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。