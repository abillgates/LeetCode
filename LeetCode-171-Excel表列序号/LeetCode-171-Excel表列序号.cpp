// LeetCode-171-Excel表列序号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
class Solution {
public:
	int titleToNumber(string s) {
		int n = s.length();
		int res = 0;
		for (int i = 0; i < n; i++) {
			int temp = s[i] - 'A' + 1;
			res = res * 26 + temp;
		}
		return res;
	}
};
int main()
{
	string s = "ZY";
	cout << Solution().titleToNumber(s);
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
//给定一个Excel表格中的列名称，返回其相应的列序号。
//
//例如，
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//示例 1:
//
//输入: "A"
//	输出 : 1
//	示例 2 :
//
//	输入 : "AB"
//	输出 : 28
//	示例 3 :
//
//	输入 : "ZY"
//	输出 : 701
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/excel-sheet-column-number
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。