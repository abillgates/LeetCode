// LeetCode-119-杨辉三角II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> getRow0(int rowIndex) {
		vector<int> res = { 1 };
		if (rowIndex == 0)
			return res;
		vector<int> temp;
		while (rowIndex)
		{
			temp.push_back(1);
			for (int i = 1; i < res.size(); i++) {
				temp.push_back(res[i] + res[i - 1]);
			}
			temp.push_back(1);
			res = temp;
			temp.clear();
			rowIndex--;
		}
		return res;
	}
	vector<int> getRow(int rowIndex) {  //O(K)
		vector<int> res(rowIndex + 1,0);
		res[0] = 1;
		for (int i = 1; i <= rowIndex; i++) {
			for (int j = i; j >= 1; j--) {
				res[j] = res[j] + res[j - 1];
			}
		}
		return res;
	}
};
int main()
{
	vector<int> result = Solution().getRow(1);
	for (int i : result) {
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
//给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
//
//
//
//在杨辉三角中，每个数是它左上方和右上方的数的和。
//
//示例 :
//
//输入: 3
//	输出 : [1, 3, 3, 1]
//	进阶：
//
//	你可以优化你的算法到 O(k) 空间复杂度吗？
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/pascals-triangle-ii
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。