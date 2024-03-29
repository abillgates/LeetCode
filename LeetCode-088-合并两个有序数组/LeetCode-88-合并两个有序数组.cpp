// LeetCode-88-合并两个有序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void merge0(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int n2 = nums2.size();
		int i = 0, j = 0;
		for (i; i < n; ) {		
			while (nums2[i]>nums1[j]&&j<=m)
			{
				j++;
			}
			nums1.insert(nums1.begin() + j, nums2[i]);
			i++;
			if (j > m)
				break;		
		}
		for (i; i < n; i++) {
			j++;
			nums1.insert(nums1.begin() + j, nums2[i]);
		}	
	}
	void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		//int n2 = nums2.size();
		int j = nums1.size()-1;
		for (int i = 0; i < n; i++) {
			nums1[j] = nums2[i];
			j--;
		}
		sort(nums1.begin(), nums1.end());
	}
	void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> num;
		for (int i = 0; i < m; i++) {
			num.push_back(nums1[i]);
		}
		int p1 = 0, p2 = 0;
		int p = 0;
		while ((p1<m)&&(p2<n))
		{
			if (num[p1] <= nums2[p2]) {
				nums1[p] = num[p1];			
				p1++;
			}
			else
			{
				nums1[p] = nums2[p2];
				p2++;
			}
			p++;
		}
		if (p1 < m) {
			while (p1<m)
			{
				nums1[p++] = num[p1++];
			}
		}
		if (p2 < n) {
			while (p2<n)
			{
				nums1[p++] = nums2[p2++];
			}
		}
	}
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		nums1.resize(m + n);
		int p = nums1.size() - 1;
		int p1 = m - 1;
		int p2 = nums2.size() - 1;
		while (p1>=0&&p2>=0)
		{
			if (nums1[p1] >= nums2[p2]) {
				nums1[p] = nums1[p1];
				p1--;
			}
			else
			{
				nums1[p] = nums2[p2];
				p2--;
			}
			p--;
		}
		if (p1 >= 0) {
			while (p1>=0)
			{
				nums1[p] = nums1[p1];
				p1--;
				p--;
			}
		}
		if (p2 >= 0) {
			while (p2>=0)
			{
				nums1[p] = nums2[p2];
				p2--;
				p--;
			}
		}
	}
};
int main()
{
	vector<int> nums1 = { 1,2,3,0,0,0 };
	vector<int> nums2 = { 2,5,6 };
	Solution().merge(nums1, 3, nums2, 3);
	for (int i : nums1) {
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
//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明 :
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//示例 :
//
//输入:
//nums1 = [1, 2, 3, 0, 0, 0], m = 3
//nums2 = [2, 5, 6], n = 3
//
//输出 : [1, 2, 2, 3, 5, 6]
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/merge-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。