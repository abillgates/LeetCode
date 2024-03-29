// LeetCode-33-搜索旋转排序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	//int search(vector<int>& nums, int target) {
	//	int minIndex = search_rotation_index(nums);
	//	int leftIndex=0,rightIndex=0;
	//	int middle = 0;
	//	if (target < nums[minIndex])
	//		return -1;
	//	if (!minIndex) {
	//		if (target > nums[nums.size() - 1]) {
	//			return -1;
	//		}
	//		else
	//		{
	//			return binarySearch(nums, target, 0, nums.size() - 1);
	//		}
	//	}
	//	else if (minIndex == nums.size() - 1) {
	//		if (target > nums[nums.size() - 2]) {
	//			return -1;
	//		}
	//		else {
	//			return binarySearch(nums, target, 0, nums.size() - 2);
	//		}
	//	}
	//	else
	//	{
	//		if (target > nums[minIndex - 1])
	//			return -1;
	//		else
	//		{
	//			if (target < nums[0])
	//				return binarySearch(nums, target, minIndex, nums.size() - 1);
	//			else
	//				return binarySearch(nums, target, 0, minIndex - 1);
	//		}
	//	}
	//}
	//int search_rotation_index(const vector<int>& nums) {
	//	int left = 0, right = nums.size() - 1;
	//	int middle = (left + right) / 2;
	//	while (left <= right) {
	//		if (nums[left] > nums[middle]) {
	//			right = middle;
	//			middle = (left + middle) / 2;
	//			if (right - left == 1)
	//				return right;
	//		}
	//		else if (nums[middle] > nums[right]) {
	//			left = middle;
	//			middle = (left + right) / 2;
	//			if (right - left == 1)
	//				return right;
	//		}
	//	}
	//	return 0;
	//}
	//int binarySearch(const vector<int>& nums, int key,int left,int right) {
	//	//int left = 0, right = nums.size() - 1;
	//	while (left<=right)
	//	{
	//		if (left == key)
	//			return left;
	//		else if (right == key)
	//			return right;
	//		int middle = (left + right) / 2;
	//		if (nums[middle] > key)
	//			right = middle - 1;
	//		else if (nums[middle] == key)
	//			return middle;
	//		else
	//			left = middle + 1;
	//	}
	//	return -1;
	//}
	int search(vector<int> nums, int target) {
		int n = nums.size();
		if (n == 0)
			return -1;
		if (n == 1)
			return nums[0] == target ? 0 : -1;
		int left = 0, right = n - 1;
		
		while (left<=right)
		{
			int middle = (left + right) / 2;
			if (nums[left] == target)
				return left;
			if (nums[right] == target)
				return right;
			if (nums[middle] == target)
				return middle;
			if (nums[left] < nums[middle]) {
				if (target > nums[left]&&target < nums[middle]) {
					right = middle - 1;
				}
				else
				{
					left = middle + 1;
				}
			}
			else
			{
				if (target > nums[middle] && target < nums[left]) {
					left = middle + 1;
				}
				else {
					right = middle - 1;
				}
			}
		}
		return -1;
	}
};
int main()
{
	vector<int> num = {5,1,2,3,4};
	cout << Solution().search(num,1);
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

//假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//
//(例如，数组 [0, 1, 2, 4, 5, 6, 7] 可能变为 [4, 5, 6, 7, 0, 1, 2])。
//
//搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回  - 1 。
//
//你可以假设数组中不存在重复的元素。
//
//你的算法时间复杂度必须是 O(log n) 级别。
//
//示例 1:
//
//输入: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
//	输出 : 4
//	示例 2 :
//
//	输入 : nums = [4, 5, 6, 7, 0, 1, 2], target = 3
//	输出 : -1

	