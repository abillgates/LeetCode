// LeetCode-055-跳跃游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	enum status
	{
		UNKNOWN,
		GOOD,
		BAD
	};
	bool canJump0(vector<int>& nums) {
		return canJumpLast(0, nums);
	}
	bool canJumpLast(int start, const vector<int>& nums) {
		int furthestJump = start + nums[start];
		if (start == nums.size() - 1) {
			return true;
		}
		for (int i = start+1; i < nums.size() && i<=furthestJump; i++) {
			if (canJumpLast(i, nums)) {
				return true;
			}
		}
		return false;
	}
	bool canJump1(vector<int>& nums) {
		vector<status> memo(nums.size(),UNKNOWN);
		memo[nums.size() - 1] = GOOD;
		return canJumpFrom(0, nums,memo);
	}
	bool canJumpFrom(int position,vector<int> nums,vector<status> memo) {
		if (position == nums.size()-1) {
			return true;
		}
		int furthestJump = position + nums[position];
		if (furthestJump > nums.size() - 1) {
			furthestJump = nums.size() - 1;
		}
		for (int i = position + 1; i <= furthestJump; i++) {
			if (canJumpFrom(i, nums, memo)) {
				memo[i] = GOOD;
				return true;
			}		
		}
		memo[position] = BAD;
		return false;
	}
	bool canJump2(vector<int>& nums) {
		vector<status> memo(nums.size(), UNKNOWN);
		memo[nums.size() - 1] = GOOD;
		for (int i = nums.size() - 2; i >= 0; i--) {
			int furthestJump = i + nums[i];
			if (furthestJump > nums.size() - 1) {
				furthestJump = nums.size() - 1;
			}
			for (int j = i + 1; j <= furthestJump; j++) {
				if (memo[j] == GOOD) {
					memo[i] = GOOD;
					break;
				}
			}
			if (memo[i] == UNKNOWN) {
				memo[i] = BAD;
			}
		}
		return memo[0] == GOOD ? true : false;
	}
	bool canJump(vector<int> nums) {
		int leftGoodindex = nums.size() - 1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			int furthestJump = i + nums[i];
			if (furthestJump >= leftGoodindex) {
				leftGoodindex = i;
			}
		}
		return leftGoodindex == 0;
	}
};
int main()
{
	vector<int> nums = { 2, 3, 1, 1, 4 };
	vector<int> nums1{ 3, 2, 1, 0, 4 };
	cout << Solution().canJump(nums);
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
//给定一个非负整数数组，你最初位于数组的第一个位置。
//
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
//判断你是否能够到达最后一个位置。
//
//示例 1 :
//
//输入: [2, 3, 1, 1, 4]
//	输出 : true
//	解释 : 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
//	示例 2 :
//
//输入: [3, 2, 1, 0, 4]
//	输出 : false
//	解释 : 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/jump-game
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。