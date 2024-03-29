// LeetCode-221-最大正方形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (!m)
			return 0;
		int n = matrix[0].size();	
		int maxlen = 0;
		int x[] = { -1,-1,0 };
		int y[] = { -1,0,-1 };
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j]=='0')
					dp[i][j] = 0;
				else {
					int min = INT_MAX;
					for (int k = 0; k < 3; k++) {						
						int temp;
						int dx = i + x[k];
						int dy = j + y[k];
						if (dx < 0 || dx >= m || dy < 0 || dy >= n) {
							temp = 0;
						}
						else {
							temp = dp[dx][dy];
						}
						if (temp < min) {
							min = temp;
						}
					}
					dp[i][j] = min + 1;
					if (dp[i][j] > maxlen) {
						maxlen = dp[i][j];
					}
				}
			}
		}
		/*for (auto i : dp) {
			for (int j : i) {
				cout << j << " ";
			}
			cout << endl;
		}*/
		return maxlen * maxlen;
	}
};
int main()
{
	vector<vector<char>> nums{
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'}
	};
	cout << Solution().maximalSquare(nums);
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
//在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
//
//示例 :
//
//输入:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//
//输出 : 4
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/maximal-square
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。