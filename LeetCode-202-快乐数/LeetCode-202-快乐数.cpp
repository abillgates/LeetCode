// LeetCode-202-快乐数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<set>
using namespace std;
class Solution {
public:
	bool isHappy(int n) {
		int s = 0;
		set<int> record;
		while (s!=1)
		{
			s = 0;
			while (n)
			{
				s = s+(n % 10)*(n % 10);
				n = n / 10;
			}
			if (record.insert(s).second == false) {
				return false;
			}
			n = s;
			//cout << s<<endl;
		}
		return true;
	}
};
int main()
{
	cout << Solution().isHappy(19);
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
//编写一个算法来判断一个数是不是“快乐数”。
//
//一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。
//
//示例 :
//
//输入: 19
//	输出 : true
//	解释 :
//	12 + 92 = 82
//	82 + 22 = 68
//	62 + 82 = 100
//	12 + 02 + 02 = 1
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/happy-number
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。