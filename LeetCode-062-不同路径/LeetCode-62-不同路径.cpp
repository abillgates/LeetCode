// LeetCode-62-不同路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePaths0(int m, int n) {
		if (m == 1) {
			return 1;
		}
		if (n == 1) {
			return 1;
		}
		else
		{
			return uniquePaths(n-1,m) + uniquePaths(n,m-1);
		}
	}
	int uniquePaths(int m, int n) {
		vector<vector<int>> res(n,vector<int>(m,1));
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				res[i][j] = res[i - 1][j] + res[i][j - 1];
			}
		}
		return res[n - 1][m - 1];
	}
};
int main()
{
	int res = Solution().uniquePaths(3,2);
	cout << res;
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
