// LeetCode-238-除自身以外数组的乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/*vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size());
		int max = 1;
		for (int i = 0; i < nums.size(); i++) {
			max = max * nums[i];
		}
		for (int i = 0; i < nums.size(); i++) {
			res[i] = max / nums[i];
		}
		return res;
	}*/
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size(), 1);
		int leftProduct = 1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			res[i] = res[i + 1] * nums[i+1];
		}
		for (int i = 1; i < nums.size(); i++) {
			leftProduct = leftProduct * nums[i - 1];
			res[i] = res[i] * leftProduct;
		}
		return res;
	}
};
int main()
{
	vector<int> num{ 1,2,3,4 };
	for (int i : Solution().productExceptSelf(num)) {
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
//给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//
//示例 :
//
//输入: [1, 2, 3, 4]
//	输出 : [24, 12, 8, 6]
//	说明 : 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//
//	进阶：
//	你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/product-of-array-except-self
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。