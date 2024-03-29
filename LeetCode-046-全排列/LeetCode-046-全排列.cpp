// LeetCode-046-全排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<iomanip>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int n = nums.size() - 1;
		vector<vector<int>> res;
		Permute(res, nums, 0, n);
		return res;
	}
	void Permute(vector<vector<int>>& result,vector<int>& nums,int left,int right) {
		if (left == right) {
			result.push_back(nums);
		}
		for (int i = left; i <=right; i++) {
			swap(nums[i], nums[left]);
			Permute(result, nums, left+1, right);
			swap(nums[i], nums[left]);
		}
	}
};
int main()
{
	vector<int> num{ 1,2,3,4 };
	auto res = Solution().permute(num);
	cout << setw(2) << res.size() << endl;
	for (auto i : res) {
		for (auto j : i) {
			cout << setw(2) << j;
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
//给定一个没有重复数字的序列，返回其所有可能的全排列。
//
//示例 :
//
//输入: [1, 2, 3]
//	输出 :
//	[
//		[1, 2, 3],
//		[1, 3, 2],
//		[2, 1, 3],
//		[2, 3, 1],
//		[3, 1, 2],
//		[3, 2, 1]
//	]
//
//	来源：力扣（LeetCode）
//		链接：https ://leetcode-cn.com/problems/permutations
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。