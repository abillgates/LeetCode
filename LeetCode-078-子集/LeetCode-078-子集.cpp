// LeetCode-078-子集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsets0(vector<int>& nums) {
		vector <vector<int>> res(1);
		for (int i = 0; i < nums.size(); i++) {
			int n = res.size();
			for (int j = 0; j < n; j++) {
				res.push_back(res[j]);
				res.back().push_back(nums[i]);
			}
		}
		return res;
	}
	vector<vector<int>> subsets1(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> output;
		generateSet(res, output, nums,0);
		return res;
	}
	void generateSet(vector<vector<int>>& res, vector<int>& output, vector<int> nums, int pos) {
		res.push_back(output);
		for (int i = pos; i < nums.size(); i++) {
			output.push_back(nums[i]);
			generateSet(res, output, nums, i + 1);
			output.pop_back();
		}
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector <vector<int>> res;
		int l = nums.size();
		int max = 1 << l;
		for (int i = 0; i < max; i++) {
			int index = 0;
			vector<int> out;
			for (int j = i; j > 0; j >>= 1) {
				if ((j & 1) == 1) {
					out.push_back(nums[index]);
				}
				index++;
			}
			res.push_back(out);
		}
		return res;
	}
};
int main()
{
	vector<int> nums{ 1,2,3 };
	for (auto i : Solution().subsets(nums)) {
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
//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
//说明：解集不能包含重复的子集。
//
//示例 :
//
//输入: nums = [1, 2, 3]
//	输出 :
//	[
//		[3],
//		[1],
//		[2],
//		[1, 2, 3],
//		[1, 3],
//		[2, 3],
//		[1, 2],
//		[]
//	]
//
//	来源：力扣（LeetCode）
//		链接：https ://leetcode-cn.com/problems/subsets
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。