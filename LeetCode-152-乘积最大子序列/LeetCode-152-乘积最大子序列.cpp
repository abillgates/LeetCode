// LeetCode-152-乘积最大子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProduct0(vector<int>& nums) { //almost timeout
		int n = nums.size();
		int maxProduct = INT_MIN;
		for (int i = 0; i < n; i++) {
			int temp = 1;
			for (int j = i; j < n; j++) {
				temp = temp * nums[j];
				if (temp > maxProduct) {
					maxProduct = temp;
				}
			}
		}
		return maxProduct;
	}
	int maxProduct(vector<int>& nums) {
		int maxPro = nums[0];
		int imin = nums[0];
		int imax = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < 0) {
				swap(imax, imin);
			}
			imax =max(imax*nums[i], nums[i]);
			imin =min(imin*nums[i], nums[i]);
			maxPro = max(imax, maxPro);
		}
		return maxPro;
	}
};
int main()
{
	vector<int> num{ 2,3,-2,4 };
	cout << Solution().maxProduct(num);
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
//给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
//
//示例 1:
//
//输入: [2, 3, -2, 4]
//	输出 : 6
//	解释 : 子数组[2, 3] 有最大乘积 6。
//	示例 2 :
//
//	输入 : [-2, 0, -1]
//	输出 : 0
//	解释 : 结果不能为 2, 因为[-2, -1] 不是子数组。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/maximum-product-subarray
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。