// LeetCode-204-计数质数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int countPrimes0(int n) {
		int count = 0;
		for (int i = 1; i < n; i++) {
			if (isPrime(i)) {
				cout << i << isPrime(i) << endl;
				count++;
			}
		}
		return count;
	}
	bool isPrime(int n) {
		if (n <= 1) {
			return false;
		}	
		for (int i = 2; i <= n / 2; i++) {
			if (n%i == 0) {
				return false;
			}
		}
		return true;
	}
	int countPrimes(int n) {
		vector<bool> prime(n + 1, true);
		int res = 0;
		for (int i = 2; i*i <=n; i++) {
			if (!prime[i])
				continue;
			for (int j = 2; j*i <= n; j++) {
				prime[j*i] = false;
			}
		}
		for (int i = 2; i < n; i++) {
			if (prime[i]) {
				res++;
			}
		}
		return res;
	}
};
int main()
{
	cout << Solution().countPrimes(10);
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
//统计所有小于非负整数 n 的质数的数量。
//
//示例 :
//
//输入: 10
//	输出 : 4
//	解释 : 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。