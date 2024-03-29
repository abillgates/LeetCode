// LeetCode-209-长度最小的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int minSubArrayLen0(int s, vector<int>& nums) {	
		int n = nums.size();
		int res = n + 1;
		vector<int> sum(n+1,0);
		for (int i = 0; i < n; i++) {
			sum[i + 1] = sum[i] + nums[i];
		}
		for (int i = 0; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (sum[j] - sum[i] >= s&&(j-i)<res) {
					res = j - i;
				}
			}
		}
		return res == n + 1 ? 0 : res;
	}
	int minSubArrayLen1(int s, vector<int>& nums) {
		int res = nums.size() + 1, left = 0, sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum = sum + nums[i];
			while (left<=i&&sum>=s)
			{
				res = res < i - left + 1 ? res : i - left + 1;
				sum = sum - nums[left];
				left++;
			}
		}
		return res == nums.size() + 1 ? 0 : res;
	}
	int minSubArrayLen(int s, vector<int>& nums) {  //refe
		int res = nums.size() + 1;
		vector<int> sum(nums.size() + 1,0);
		for (int i = 1; i <= nums.size(); i++) {
			sum[i] = sum[i - 1] + nums[i - 1];
		}
		for (int i = 0; i <= nums.size(); i++) {
			int right = binarySearch(i + 1, nums.size(), sum, sum[i] + s);
			if (right == nums.size() + 1) {
				break;
			}
			if (res > right - i) {
				res = right - i;
			}
		}
		return res == nums.size() + 1 ? 0 : res;
	}
	int binarySearch(int left, int right, vector<int> nums,int target) {
		while (left<=right)
		{
			int middle = (left + right) / 2;
			if (nums[middle] >= target) {
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
		return left;
	}
};
int main()
{
	vector<int> num{ 2,3,1,2,4,3 };
	cout << Solution().minSubArrayLen(7,num);
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
//给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
//
//示例: 
//
//输入: s = 7, nums = [2,3,1,2,4,3]
//输出: 2
//解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。