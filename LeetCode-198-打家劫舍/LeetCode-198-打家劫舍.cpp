// LeetCode-198-打家劫舍.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		if (nums.size() == 1) {
			return nums[0];
		}
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return dp[nums.size() - 1];
	}
	int max(int a, int b) {
		return a >= b ? a : b;
	}
};
int main()
{
	vector<int> num{ 2, 7, 9, 3, 1 };
	cout << Solution().rob(num);
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
//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
//
//示例 1:
//
//输入: [1, 2, 3, 1]
//	输出 : 4
//	解释 : 偷窃 1 号房屋(金额 = 1) ，然后偷窃 3 号房屋(金额 = 3)。
//	偷窃到的最高金额 = 1 + 3 = 4 。
//	示例 2 :
//
//	输入 : [2, 7, 9, 3, 1]
//	输出 : 12
//	解释 : 偷窃 1 号房屋(金额 = 2), 偷窃 3 号房屋(金额 = 9)，接着偷窃 5 号房屋(金额 = 1)。
//	偷窃到的最高金额 = 2 + 9 + 1 = 12 。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/house-robber
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。