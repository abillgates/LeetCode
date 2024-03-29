// LeetCode-228-汇总区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		int n = nums.size();
		if (!n) {
			return{};
		}
		for (int i = 0; i < n; i++) {
			string temp="";
			int begin = nums[i];
			temp += to_string(nums[i]);
			while (i+1<n)
			{
				if (nums[i + 1] - 1 != nums[i])
					break;
				i++;
			}
			if (nums[i] != begin) {
				temp += "->";
				temp += to_string(nums[i]);
			}
			res.push_back(temp);
		}
		return res;
	}
};
int main()
{
	//vector<int> num{ 0,1,2,4,5,7 };
	vector<int> num{ INT_MIN,-2147483647,2147483647 };
	auto res = Solution().summaryRanges(num);
	for (string i : res) {
		cout << i <<",";
	}
	//cout << "123";
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
//给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
//
//示例 1:
//
//输入: [0, 1, 2, 4, 5, 7]
//	输出 : ["0->2", "4->5", "7"]
//	解释 : 0, 1, 2 可组成一个连续的区间; 4, 5 可组成一个连续的区间。
//	示例 2:
//
//输入: [0, 2, 3, 4, 6, 8, 9]
//	输出 : ["0", "2->4", "6", "8->9"]
//	解释 : 2, 3, 4 可组成一个连续的区间; 8, 9 可组成一个连续的区间。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/summary-ranges
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。