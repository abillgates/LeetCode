// LeetCode-43-字符串相乘.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		int n1 = num1.length()-1;
		int n2 = num2.length()-1;
		string result;
		if((n1==1&&num1[0]=='0')||(n2==1&&num2[0]=='0'))
			return "0";
		if (n1 < n2) {
			swap(num1, num2);
			swap(n1, n2);
		}
		for (int i = n2; i >= 0; i--) {
			string singleReuslt = multi_One_by_One(num1, num2[i], n2 - i);
			result = addStrings(result, singleReuslt);
		}
		return result;		
	}
	string addStrings1(string num1, string num2) {
		vector<int> nums1;
		vector<int> nums2;
		vector<int> sum;
		for (int i = num1.size()-1; i >= 0; i--) {
			nums1.push_back(num1[i] - '0');
		}
		for (int i = num2.size()-1; i >= 0; i--) {
			nums2.push_back(num2[i] - '0');
		}
		int i = 0;
		int carry = 0;
		while (i<nums1.size()&&i<nums2.size())
		{
			int temp = nums1[i] + nums2[i] + carry;
			carry = temp / 10;
			sum.push_back(temp % 10);
			i++;
		}
		if (i == nums1.size()&&i==nums2.size()) {
			
		}
		else if(i==nums1.size())
		{
			while (i<nums2.size())
			{
				int temp = carry + nums2[i];
				carry = temp / 10;
				sum.push_back(temp % 10);
				i++;
			}			
		}
		else
		{
			while (i<nums1.size())
			{
				int temp = carry + nums1[i];
				carry = temp / 10;
				sum.push_back(temp % 10);
				i++;
			}
		}
		if (carry != 0) {
			sum.push_back(carry);
		}
		string result;
		for (i = sum.size() - 1; i >= 0; i--) {
			result.push_back(sum[i] + '0');
		}
		return result;	
	}
	string addStrings(string num1, string num2) {
		int n1 = num1.size() - 1;
		int n2 = num2.size() - 1;
		int carry = 0;
		string result;
		while (n1>=0||n2>=0)
		{
			if (n1 >= 0) {
				carry = carry + num1[n1] - '0';
			}
			if (n2 >= 0) {
				carry = carry + num2[n2] - '0';
			}
			result.push_back(carry % 10 + '0');
			carry = carry / 10;
			n1--;
			n2--;
		}
		if (carry == 1)
			result.push_back(carry + '0');
		reverse(result.begin(), result.end());
		return result;
	}
	string multi_One_by_One(string num1, char m, int carry) {
		int multi = m - '0';
		int n = num1.size() - 1;
		int addCarry = 0;
		string result;
		while (n>=0)
		{
			addCarry = addCarry + (num1[n] - '0')*multi;
			result.push_back(addCarry % 10 + '0');
			addCarry = addCarry / 10;
			n--;
		}
		if (addCarry!=0)
			result.push_back(addCarry + '0');
		reverse(result.begin(), result.end());
		while (carry)
		{
			result.push_back('0');
			carry--;
		}
		return result;
	}
};
int main()
{
	string s1 = "9";
	string s2 = "9";
	//cout << Solution().multi_One_by_One(s1,'6',2);
	cout << Solution().multiply(s1, s2);
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
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
//示例 1:
//
//输入: num1 = "2", num2 = "3"
//	输出 : "6"
//	示例 2 :
//
//	输入 : num1 = "123", num2 = "456"
//	输出 : "56088"
//	说明：
//
//	num1 和 num2 的长度小于110。
//	num1 和 num2 只包含数字 0 - 9。
//	num1 和 num2 均不以零开头，除非是数字 0 本身。
//	不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/multiply-strings
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。