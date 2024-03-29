// LeetCode-168-Excel表列名称.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
	string convertToTitle0(int n) {
		string res;
		while (n)
		{
			char c = 'A' + (n - 1) % 26;
			n = (n-1) / 26;
			res = res + c;
		}
		for (int i = 0; i < res.length()/2; i++) {
			char temp;
			temp = res[i];
			res[i] = res[res.length() - 1 - i];
			res[res.length() - 1 - i] = temp;
		}
		return res;
	}
	string convertToTitle(int n) {
		string res = {};
		while (n)
		{
			n--;
			char c = 'A' + n % 26;
			n = n / 26;
			res.insert(res.begin(), c);
		}
		return res;
	}
};
int main()
{
	cout << Solution().convertToTitle(701);
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
//给定一个正整数，返回它在 Excel 表中相对应的列名称。
//
//例如，
//
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB
//...
//示例 1:
//
//输入: 1
//	输出 : "A"
//	示例 2 :
//
//	输入 : 28
//	输出 : "AB"
//	示例 3 :
//
//	输入 : 701
//	输出 : "ZY"
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/excel-sheet-column-title
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。