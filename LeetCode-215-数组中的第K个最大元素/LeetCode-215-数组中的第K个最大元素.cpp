// LeetCode-215-数组中的第K个最大元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (nums[j] > nums[i]) {
					swap(nums[j], nums[i]);
				}
			}
			if (i == k - 1) {
				break;
			}
		}
		//cout << endl;
		return nums[k - 1];
	}
};
int main()
{
	vector<int> num{ 3,2,1,5,6,4 };
	cout << Solution().findKthLargest(num,2);
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
//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//示例 1:
//
//输入: [3, 2, 1, 5, 6, 4] 和 k = 2
//	输出 : 5
//	示例 2 :
//
//	输入 : [3, 2, 3, 1, 2, 4, 5, 5, 6] 和 k = 4
//	输出 : 4
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/kth-largest-element-in-an-array
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。