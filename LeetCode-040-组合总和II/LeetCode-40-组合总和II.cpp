// LeetCode-40-组合总和II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> temp;
		sort(candidates.begin(), candidates.end());
		traceback(candidates, 0, target, temp, result);
		return result;
	}
	void traceback(const vector<int> candidates, int start, int target, vector<int>& temp, vector<vector<int>>& result) {
		if (target == 0) {
			result.push_back(temp);
			return;
		}
		if (target < 0) {
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			temp.push_back(candidates[i]);
			traceback(candidates, i + 1, target - candidates[i], temp, result);
			temp.pop_back();
		}
	}
};
int main()
{
	vector<int> nums{ 10,1,2,7,6,1,5 };
	1, 1, 2, 5, 6, 7, 10;
	int target = 8;
	auto result = Solution().combinationSum2(nums, target);
	
	for (auto i : result) {
		cout << "[";
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "]" << endl;
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
