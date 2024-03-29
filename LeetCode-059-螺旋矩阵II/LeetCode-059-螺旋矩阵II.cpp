// LeetCode-059-螺旋矩阵II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		int count = 0;
		int rowt = 0, rowb = n-1, coll = 0, colr = n-1;
		while (colr >= coll)
		{
			for (int i =coll; i <= colr; i++) {
				res[rowt][i] = ++count;
			}
			rowt++;
			for (int i =rowt; i <= rowb; i++) {
				res[i][colr] = ++count;
			}
			colr--;
			for (int i = colr; i >= coll; i--) {
				res[rowb][i] = ++count;
			}
			rowb--;
			for (int i = rowb; i >= rowt; i--) {
				res[i][coll] = ++count;
			}
			coll++;
		}
		return res;
	}
};
int main()
{
	auto num = Solution().generateMatrix(3);
	for (auto i : num) {
		for (auto j : i) {
			cout << j << " ";
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
//给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
//
//示例 :
//
//输入: 3
//	输出 :
//	[
//		[1, 2, 3],
//		[8, 9, 4],
//		[7, 6, 5]
//	]
//
//	来源：力扣（LeetCode）
//		链接：https ://leetcode-cn.com/problems/spiral-matrix-ii
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。