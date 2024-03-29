// LeetCode-136-只出现一次的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
	int singleNumber0(const vector<int>& nums) {
		set<int> num1;
		int sum = 0;
		int sum1 = 0;
		for (int i = 0; i < nums.size(); i++) {
			num1.insert(nums[i]);
			sum = sum + nums[i];
		}
		for (set<int>::iterator it = num1.begin(); it != num1.end(); it++) {
			sum1 = sum1 + *it;
			//cout << *it << " ";
		}
		return 2 * sum1 - sum;
	}
	int singleNumber1(const vector<int>& nums) {
		unordered_map<int, int> hash;
		for (int i = 0; i < nums.size(); i++) {
			hash[nums[i]]++;
		}
		int result = 0;
		for (unordered_map<int, int>::iterator it = hash.begin(); it != hash.end(); it++) {
			if (it->second == 1) {
				result=it->first;
			}
		}
		return result;
	}
	int singleNumber(vector<int>& nums) {
		int result = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			result = result ^ nums[i];
		}
		return result;
	}
};
int main()
{
	vector<int> num{ 2,2,1 };
	cout << Solution().singleNumber1(num);
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
//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//
//说明：
//
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//
//示例 1:
//
//输入: [2, 2, 1]
//	输出 : 1
//	示例 2 :
//
//	输入 : [4, 1, 2, 1, 2]
//	输出 : 4
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/single-number
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。