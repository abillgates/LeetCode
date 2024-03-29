// LeetCode三数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size();
		int Closestdiff = abs(nums[0] + nums[1] + nums[2],target);
		int temp = abs(nums[0] + nums[1] + nums[2],target);
		int Closestnumber = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < n - 2; i++) {
			for (int j = i+1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					temp = abs(nums[i] + nums[j] + nums[k],target);					
					if (temp < Closestdiff) {
						Closestdiff = temp;
						Closestnumber = nums[i] + nums[j] + nums[k];
					}
				}
			}
		}
		return Closestnumber;
	}
	int threeSumClosest1(vector<int>& nums, int target) {
		int n = nums.size();
		sort(nums.begin(),nums.end());
		int Closestdiff = abs(nums[0] + nums[1] + nums[2], target);
		int temp = Closestdiff;
		int Closestnumber = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < n - 2; i++) {
			int Firstfix = nums[i];
			int left = i + 1;
			int right = n - 1;
			while (left < right) {
				int sum = Firstfix + nums[left] + nums[right];
				temp = abs(sum , target);
				if (temp == 0) {
					return target;
				}
				if (temp < Closestdiff) {
					Closestdiff = temp;
					Closestnumber = sum;
				}
				if (sum - target < 0)
					left++;
				else
					right--;
			}
		}
		return Closestnumber;
	}
	int abs(int a, int b) {
		if (a - b < 0) {
			return b - a;
		}
		else
			return a - b;
	}
};
int main()
{
	vector<int> a = { -1,2,1,- 4 };
	cout << Solution().threeSumClosest1(a,1);
    //std::cout << "Hello World!\n"; 
	return 0;
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
