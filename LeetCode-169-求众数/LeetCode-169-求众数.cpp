// LeetCode-169-求众数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> count;
		int res;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			count[nums[i]]++;
			if (count[nums[i]] > n / 2) {
				res = nums[i];
			}
		}
		return res;
	}
};
int main()
{
	vector<int> num{ 2,2,1,1,1,2,2 };
	cout << Solution().majorityElement(num);
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
//给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n / 2 ⌋ 的元素。
//
//你可以假设数组是非空的，并且给定的数组总是存在众数。
//
//示例 1 :
//
//输入: [3, 2, 3]
//	输出 : 3
//	示例 2 :
//
//	输入 : [2, 2, 1, 1, 1, 2, 2]
//	输出 : 2
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/majority-element
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。