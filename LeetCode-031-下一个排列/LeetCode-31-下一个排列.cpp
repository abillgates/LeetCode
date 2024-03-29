// LeetCode-31-下一个排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() == 1)return;
		/*else if (nums.size() == 2) {
			swap(nums[0], nums[1]);
			return;
		}*/
		int n = nums.size()-1;
		bool flag = false;

		int i = n,j=n-1;
		
		while (j && (nums[j]>=nums[i]))
		{
			j--;
			i--;
		}
		if (j == 0 && i == 1) {
			if (nums[j] >=nums[i])
				reverse(nums.begin(), nums.end());
			else {
				int tempindex = n;
				while (nums[j] >= nums[tempindex])
					tempindex--;
				swap(nums[j], nums[tempindex]);
				reverse(nums.begin() + j + 1, nums.end());
			}
		}
		else
		{
			int tempindex = n;
			while (nums[j] >= nums[tempindex])
				tempindex--;
			swap(nums[j], nums[tempindex]);
			reverse(nums.begin() + j + 1, nums.end());
		}
		/*int tempindex = 0;
		for (i = n; i>=1; i--) {
			bool existBig = false;
			for (j = i - 1; j >= 0; j--) {
				if (!existBig) {
					if (nums[j] > nums[i]) {
						tempindex = j;
						existBig = true;
					}
				}
				if (nums[j] == nums[i]) {
					if ((j - i > 1)&&existBig) {
						flag = true;
						swap(nums[j], nums[tempindex]);
						break;
					}
				}
				else if (nums[j] < nums[i]) {				
					flag = true;
					swap(nums[i], nums[j]);
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			reverse(nums.begin() + j + 1, nums.end());
		else
			reverse(nums.begin(), nums.end());
*/
		/*while (--i)
		{
			if (nums[i] < nums[n])
				break;
		}
		if (i == 0 && nums[i] > nums[n])
			reverse(nums.begin(), nums.end());
		else
		{

			swap(nums[i], nums[n]);
			reverse(nums.begin() + i+1, nums.end());
		}	*/
	}
};
int main()
{
	//[4,2,0,2,3,2,0]
	//1,2,5,4,3
	//5,4,3,2,1
	//5,2,4,3,1
	//7,5,6,4,3
	//3,4,2,1
	vector<int> num = { 2,3,1 };
	Solution().nextPermutation(num);
	for (int i : num)
		cout << i << " ";
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
