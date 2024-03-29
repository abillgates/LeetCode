// LeetCode-219-存在重复元素II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int,int> check;
		for (int i = 0; i < nums.size(); i++) {
			if (check.count(nums[i])==0) {
				check.insert({ nums[i], i });
			}
			else
			{
				if (i - check[nums[i]] <= k) {
					return true;
				}
				else
				{
					check[nums[i]] = i;
				}
			}
		}
		return false;
	}
};
int main()
{
	vector<int> num{ 1,0,1,1 };
	cout << Solution().containsNearbyDuplicate(num,1);
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
//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums[i] = nums[j]，并且 i 和 j 的差的绝对值最大为 k。
//
//示例 1 :
//
//输入: nums = [1, 2, 3, 1], k = 3
//	输出 : true
//	示例 2 :
//
//	输入 : nums = [1, 0, 1, 1], k = 1
//	输出 : true
//	示例 3 :
//
//	输入 : nums = [1, 2, 3, 1, 2, 3], k = 2
//	输出 : false
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/contains-duplicate-ii
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。