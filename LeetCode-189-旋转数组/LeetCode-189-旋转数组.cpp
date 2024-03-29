// LeetCode-189-旋转数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void rotate0(vector<int>& nums, int k) { //Time out
		int n = nums.size();
		k = k % n;
		while (k--)
		{
			for (int i = n - 1; i >0; i--) {
				int temp = nums[i];
				nums[i] = nums[i - 1];
				nums[i - 1] = temp;
			}
		}
	}
	void rotate1(vector<int>& nums, int k) { //two much space
		int n = nums.size();
		vector<int> res(n);
		for (int i = n - 1; i >= 0; i--) {
			res[(i + k) % n] = nums[i];
		}
		nums = res;	
	}
	void rotate(vector<int>& nums, int k) {  //reference
		int n = nums.size();
		k = k % n;
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
	}
};
int main()
{
	vector<int> nums{ 1,2,3,4,5,6,7 };
	Solution().rotate(nums,3);
	for (int i : nums) {
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
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//示例 1:
//
//输入: [1, 2, 3, 4, 5, 6, 7] 和 k = 3
//	输出 : [5, 6, 7, 1, 2, 3, 4]
//	解释 :
//	向右旋转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//	向右旋转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//	向右旋转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//	示例 2 :
//
//	输入 : [-1, -100, 3, 99] 和 k = 2
//	输出 : [3, 99, -1, -100]
//	解释 :
//	向右旋转 1 步 : [99, -1, -100, 3]
//	向右旋转 2 步 : [3, 99, -1, -100]
//	说明 :
//
//	尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
//	要求使用空间复杂度为 O(1) 的 原地 算法。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/rotate-array
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//  环状替换