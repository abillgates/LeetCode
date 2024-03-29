// LeetCode-121-买卖股票的最佳时机.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int maxProfit0(vector<int>& prices) { // too complex
		int n = prices.size();
		if (n == 1) {
			return 0;
		}
		int max = 0;
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (prices[j] - prices[i] > max) {
					max = prices[j] - prices[i];
				}
			}
		}
		return max;
	}
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 1) {
			return 0;
		}
		int maxprice=0,maxprofit=0;
		for (int i = prices.size() - 1; i >= 0; i--) {
			if (prices[i] > maxprice) {
				maxprice = prices[i];
			}
			else
			{
				if (maxprice - prices[i] > maxprofit) {
					maxprofit = maxprice - prices[i];
				}
			}
		}
		return maxprofit;
	}
	/*int maxsum(vector<int>& num) {
		int n = num.size() - 1;
		int sum = 0;
		int max = 0;
		for (int i = 0; i <=n; i++) {
			if (sum < 0) {
				sum = num[i];
			}
			else
			{
				sum = sum + num[i];
			}
			if (sum > max)
				max = sum;
		}
		return max;
	}*/
};
int main()
{
	vector<int> sum = { 7,1,5,3,6,4 };
	cout << Solution().maxProfit(sum);
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
//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//
//如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//
//注意你不能在买入股票前卖出股票。
//
//示例 1:
//
//输入: [7, 1, 5, 3, 6, 4]
//	输出 : 5
//	解释 : 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6 - 1 = 5 。
//	注意利润不能是 7 - 1 = 6, 因为卖出价格需要大于买入价格。
//	示例 2 :
//
//	输入 : [7, 6, 4, 3, 1]
//	输出 : 0
//	解释 : 在这种情况下, 没有交易完成, 所以最大利润为 0。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。