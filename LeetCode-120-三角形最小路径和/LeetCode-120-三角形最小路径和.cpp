// LeetCode-120-三角形最小路径和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int m = triangle.size();
		vector<vector<int>> res(m);
		for (int i = 0; i < m; i++) {
			res[i].resize(i + 1);
		}
		for (int i = m-1; i >= 0; i--) {
			for (int j = 0; j <= i; j++) {
				if (i + 1 == m) {
					res[i][j] = triangle[i][j];
				}
				else
				{
					res[i][j] = min((triangle[i][j] + res[i + 1][j]), (triangle[i][j] + res[i + 1][j + 1]));
				}
			}
		}
		return res[0][0];
	}
	int min(int a, int b) {
		return a < b ? a : b;
	}
};
int main()
{
	vector<vector<int>> num{
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};
	cout << Solution().minimumTotal(num);
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
//给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
//
//例如，给定三角形：
//
//[
//	[2],
//	[3, 4],
//	[6, 5, 7],
//	[4, 1, 8, 3]
//]
//自顶向下的最小路径和为 11（即，2  + 3 + 5 + 1 = 11）。
//
//说明：
//
//如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/triangle
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。