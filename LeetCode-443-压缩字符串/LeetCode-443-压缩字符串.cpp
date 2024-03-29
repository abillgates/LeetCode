// LeetCode-443-压缩字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	int compress(vector<char>& chars) {
		int n = chars.size();
		if (!n||n==1) {
			return n;
		}
		int curr = 0, i = 0, j = 0;
		while (j<n)
		{
			i = j;
			int count = 0;
			while (j < n&&chars[j] == chars[i]) {
				j++;
				count++;
			}
			chars[curr] = chars[i];
			if (count > 1) {
				string s = to_string(count);
				for (int k = 0; k < s.size(); k++) {
					curr++;
					chars[curr] = s[k];
				}
			}
			curr++;
		}
		for (int k = 0; k < curr; k++) {
			cout << chars[k] << ",";
		}
		return curr;
	}
};
int main()
{
	vector<char> chars{ 'a','a','b','b','c','c','c' };
	//vector<char> chars{ 'a','b','b','b','b','b','b','b','b','b','b','b','b' };
	cout << Solution().compress(chars);
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
//给定一组字符，使用原地算法将其压缩。
//
//压缩后的长度必须始终小于或等于原数组长度。
//
//数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
//
//在完成原地修改输入数组后，返回数组的新长度。
//
//
//
//进阶：
//你能否仅使用O(1) 空间解决问题？
//
//
//
//示例 1：
//
//输入：
//["a", "a", "b", "b", "c", "c", "c"]
//
//输出：
//返回6，输入数组的前6个字符应该是：["a", "2", "b", "2", "c", "3"]
//
//说明：
//"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。
//示例 2：
//
//输入：
//["a"]
//
//输出：
//返回1，输入数组的前1个字符应该是：["a"]
//
//说明：
//没有任何字符串被替代。
//示例 3：
//
//输入：
//["a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b"]
//
//输出：
//返回4，输入数组的前4个字符应该是：["a", "b", "1", "2"]。
//
//说明：
//由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
//注意每个数字在数组中都有它自己的位置。
//注意：
//
//所有字符都有一个ASCII值在[35, 126]区间内。
//1 <= len(chars) <= 1000。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/string-compression
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。