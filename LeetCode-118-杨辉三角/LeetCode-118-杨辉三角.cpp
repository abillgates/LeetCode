// LeetCode-118-杨辉三角.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<iomanip>
using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result(numRows,vector<int>(1,1));
		if (numRows == 1) {
			return result;
		}
		for (int i = 1; i <= numRows; i++) {
			result[i-1].resize(i);
			result[i - 1][i - 1] = 1;
		}
		if (numRows == 2) {
			return result;
		}
		for (int i = 3; i <=numRows; i++)
		{
			for (int j = 2; j < result[i-1].size(); j++) {
				result[i - 1][j - 1] = result[i - 2][j - 2] + result[i - 2][j - 1];
			}
		}
		return result;
	}
};
int main()
{
	auto num = Solution().generate(10);
	for (auto i : num) {
		for (auto j : i) {
			cout <<setw(6) << j ;
		}
		cout << endl;
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
//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
//
//
//
//在杨辉三角中，每个数是它左上方和右上方的数的和。
//
//示例 :
//
//输入: 5
//	输出 :
//	[
//		[1],
//		[1, 1],
//		[1, 2, 1],
//		[1, 3, 3, 1],
//		[1, 4, 6, 4, 1]
//	]
//
//	来源：力扣（LeetCode）
//		链接：https ://leetcode-cn.com/problems/pascals-triangle
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。