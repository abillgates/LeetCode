// LeetCode-54-螺旋矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) {
			return{};
		}
		int n = matrix[0].size();
		vector<int> res;
		int right =0, down = n-1, left = m-1, up =0;
		while (true)
		{
			if (right <= left) {
				for (int i = up; i <= down; i++) {
					res.push_back(matrix[right][i]);
					//cout << matrix[right][i] << " ";
				}
				right++;
			}
			if (right > left) {
				break;
			}
			if (down >= up) {
				for (int i = right; i <= left; i++) {
					res.push_back(matrix[i][down]);
					//cout << matrix[i][down] << " ";
				}
				down--;
			}
			if (left >= right) {
				for (int i = down; i >=up; i--)
				{
					res.push_back(matrix[left][i]);
					//cout << matrix[left][i] << " ";
				}
				left--;
			}
			if (up <= down) {
				for (int i = left; i >= right; i--) {
					res.push_back(matrix[i][up]);
					//cout << matrix[i][up] << " ";
				}
				up++;
			}
		}
		return res;
	}
};
int main()
{
	vector<vector<int>> num{{1,2,3},
							{4,5,6},
							{7,8,9}
	};
	vector<vector<int>> num1{{1,2,3,4},
							 {5,6,7,8},
							 {9,10,11,12}
	};
	vector<int> res = Solution().spiralOrder(num1);
	for (int i : res) {
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
//给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
//
//示例 1 :
//
//输入:
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//]
//输出 : [1, 2, 3, 6, 9, 8, 7, 4, 5]
//	示例 2 :
//
//	输入 :
//	[
//		[1, 2, 3, 4],
//		[5, 6, 7, 8],
//		[9, 10, 11, 12]
//	]
//	 输出 : [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
//
//		 来源：力扣（LeetCode）
//		 链接：https ://leetcode-cn.com/problems/spiral-matrix
//		  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。