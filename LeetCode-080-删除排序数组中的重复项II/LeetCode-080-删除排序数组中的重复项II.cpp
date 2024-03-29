// LeetCode-080-删除排序数组中的重复项II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (!n)
			return 0;
		int count = 1;
		int curr = 0, i = 0;
		for (i = 1; i < n; i++) {
			if (nums[i] == nums[i - 1]) {
				count++;
				if (count == 2) {
					nums[++curr] = nums[i];
				}
			}
			else {
				count = 1;
				nums[++curr] = nums[i];
			}
		}
		return curr + 1;
	}
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2) {
			return nums.size();
		}
		int index = 2;
		for (int i = 2; i < n; i++) {
			if (nums[i] != nums[index - 2]) {
				nums[index++] = nums[i];
			}
		}
		return index;
	}
};
int main()
{
	Solution s;
	//vector<int> nums{ 1,1,1,2,2,3 };
	vector<int> nums{ 0,0,1,1,1,1,2,3,3 };
	int n = s.removeDuplicates(nums);
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
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
//给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//
//示例 1 :
//
//给定 nums = [1, 1, 1, 2, 2, 3],
//
//函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
//
//你不需要考虑数组中超出新长度后面的元素。
//示例 2 :
//
//给定 nums = [0, 0, 1, 1, 1, 1, 2, 3, 3],
//
//函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
//
//你不需要考虑数组中超出新长度后面的元素。
//说明 :
//
//为什么返回数值是整数，但输出的答案是数组呢 ?
//
//请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
//
//你可以想象内部操作如下 :
//
//// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
//int len = removeDuplicates(nums);
//
//// 在函数里修改输入数组对于调用者是可见的。
//// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
//for (int i = 0; i < len; i++) {
//	print(nums[i]);
//}
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。