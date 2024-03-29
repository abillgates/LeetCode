// LeetCode-216-组合总和III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		if (n <= 0||k<1) {
			return{};
		}
		vector<vector<int>> res;
		vector<int> output;
		traceback(k, n, 0, 1, output, res);
		return res;
	}
	void traceback(int k, int n, int sum, int begin, vector<int>& output, vector <vector<int>>& res) {
		if (k == 0) {
			if (n == sum) {
				res.push_back(output);
			}
			return;
		}
		for (int i = begin; i <= 9; i++) {
			output.push_back(i);
			sum = sum + i;
			traceback(k - 1, n, sum, i + 1, output, res);
			sum = sum - i;
			output.pop_back();
		}
	}
};
int main()
{
	for (auto i : Solution().combinationSum3(3, 9)) {
		for (int j : i) {
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
//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
//
//说明：
//
//所有数字都是正整数。
//解集不能包含重复的组合。 
//示例 1:
//
//输入: k = 3, n = 7
//	输出 : [[1, 2, 4]]
//	示例 2 :
//
//	输入 : k = 3, n = 9
//	输出 : [[1, 2, 6], [1, 3, 5], [2, 3, 4]]
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/combination-sum-iii
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。