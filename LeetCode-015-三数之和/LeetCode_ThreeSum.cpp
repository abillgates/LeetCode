// LeetCode_ThreeSum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> sum;
		//vector<int> temp;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 2; i++) {
			int fix = nums[i];
			if (fix > 0)
				break;
			if(i>0&&fix==nums[i-1])
				continue;
			int left = i + 1;
			int right = n - 1;
			while (left<right)
			{
				int number = fix + nums[left] + nums[right];
				if (number == 0) {
					sum.push_back({ fix,nums[left],nums[right] });
					left++;
					while (left < right && nums[left] == nums[left - 1])
						left++;
					right--;
					while (right > left&&nums[right] == nums[right + 1])
						right--;
				}
				else if (number < 0) {
					left++;					
				}	
				else if (number > 0) {
					right--;						
				}				
			}
		}
		return sum;
	}
};
int main()
{
	//vector<int> num = { -4,-1,-1,0,1,2 };
	vector<int> num = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> sum = Solution().threeSum(num);
	for (auto i : sum) {
		for (auto j : i) {
			cout << j <<" ";
		}
		cout << endl;
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
