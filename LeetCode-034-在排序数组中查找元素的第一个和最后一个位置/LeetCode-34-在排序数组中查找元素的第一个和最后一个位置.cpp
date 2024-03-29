// LeetCode-34-在排序数组中查找元素的第一个和最后一个位置.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		if (nums.size()==0)
			return{ -1,-1 };
		if (nums.size() == 1) {
			if (nums[0] != target)
				return{ -1,-1 };
			else
				return{ 0,0 };
		}
		int left = 0, right = nums.size() - 1;
		int findIndex = -1;
		if (target > nums[nums.size() - 1] || target < nums[0])
			return{ -1,-1 };
		while (left<=right)
		{
			int middle = (left + right) / 2;
			if (nums[left] == target) {
				findIndex = left;
				break;
			}
			if (nums[right] == target) {
				findIndex = right;
				break;
			}
			if (nums[middle] == target) {
				findIndex = middle;
				break;
			}
			if (nums[middle] > target)
				right = middle - 1;
			else
				left = middle + 1;
		}
		if (findIndex == -1)
			return{ -1,-1 };
		else {
			int temp = findIndex;
			while (temp >= 0 && nums[temp] == target)
				temp--;
			result.push_back(temp + 1);
			temp = findIndex;
			while (temp < nums.size() && nums[temp] == target)
				temp++;
			result.push_back(temp - 1);
		}
		return result;
	}
};
int main()
{
	vector<int> num = { 5, 7, 7, 8, 8, 10 };
	for (auto i : Solution().searchRange(num, 6))
		cout << i << " ";
    //std::cout << "Hello World!\n";
	return 0;
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

//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//你的算法时间复杂度必须是 O(log n) 级别。
//
//如果数组中不存在目标值，返回 [-1, -1]。
//
//示例 1:
//
//输入: nums = [5, 7, 7, 8, 8, 10], target = 8
//	输出 : [3, 4]
//	示例 2 :
//
//	输入 : nums = [5, 7, 7, 8, 8, 10], target = 6
//	输出 : [-1, -1]
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。