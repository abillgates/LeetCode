// LeetCode-283-移动零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int i = 0, j = 0;
		while (i < nums.size()) {
			nums[j] = nums[i];
			if (nums[i])j++;
			i++;
		}
		while (j< nums.size())nums[j++] = 0;
	}
	void moveZeroes(vector<int>& nums) {
		int firstZeroAt = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				swap(nums[firstZeroAt++], nums[i]);
			}
		}
	}
};
int main()
{
	vector<int> num{ 0,1,0,3,12 };
	Solution().moveZeroes(num);
	for (int i : num) {
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
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//
//示例 :
//
//输入: [0, 1, 0, 3, 12]
//	输出 : [1, 3, 12, 0, 0]
//	说明 :
//
//	必须在原数组上操作，不能拷贝额外的数组。
//	尽量减少操作次数。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/move-zeroes
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。