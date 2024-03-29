// LeetCode-056-合并区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res;
		int m = intervals.size();
		if (!m || m == 1)
			return intervals;
		for (int i = 0; i < m; i++) {
			for (int j = i + 1; j < m; j++) {
				if (intervals[j][0] < intervals[i][0]) {
					swap(intervals[i], intervals[j]);
				}
			}
		}
		res.push_back(intervals[0]);
		for (int i = 1; i <m; i++) {
			int n = res.size();
			if (intervals[i][1] <= res[n-1][1]) {
				continue;
			}
			else if(intervals[i][0]<=res[n-1][1]){
				res[n-1][1] = intervals[i][1];
			}
			else{
				res.push_back(intervals[i]);
			}
		}
		return res;
	}
};
int main()
{
	vector<vector<int>> num{
	/*{1,3},
	{15,18},
	{2,6},
	{8,10}*/
		{0,2},
		{1,4},
		{3,5}
	};
	auto result=Solution().merge(num);
	for (auto i : result) {
		for (auto j : i) {
			cout << j << " ";
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
//给出一个区间的集合，请合并所有重叠的区间。
//
//示例 1:
//
//输入: [[1, 3], [2, 6], [8, 10], [15, 18]]
//	输出 : [[1, 6], [8, 10], [15, 18]]
//	解释 : 区间[1, 3] 和[2, 6] 重叠, 将它们合并为[1, 6].
//	示例 2 :
//
//	输入 : [[1, 4], [4, 5]]
//	输出 : [[1, 5]]
//	解释 : 区间[1, 4] 和[4, 5] 可被视为重叠区间。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/merge-intervals
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。