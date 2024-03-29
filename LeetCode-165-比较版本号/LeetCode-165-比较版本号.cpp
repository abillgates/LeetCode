// LeetCode-165-比较版本号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
class Solution {
public:
	/*int compareVersion(string version1, string version2) {
		int n1 = version1.length();
		int n2 = version2.length();
		int flag = 0;
		if (n1 < n2) {
			swap(version1, version2);
			swap(n1, n2);
			flag = 1;
		}
		int i = 0, j = 0;
		for (; i < n1&&j < n2; i++, j++) {
			while (version1[i] == '0') {
				i++;
				if (version1[i] == '.'||i==n1)
					i--;
				break;
			}
			while (version2[j] == '0') {
				j++;
				if (version2[j] == '.'||j==n2)
					j--;
				break;
			}
			if (version1[i] == '.')continue;
			if (version1[i] > version2[j]) {
				if (i != n1 - 1) {
					if (!flag)return 1;
					else return -1;
				}
			}
			else if (version1[i] < version2[j]) {
				if (j != n2 - 1) {
					if (!flag)return -1;
					else return 1;
				}
			}
		}
		if (i == n1 && j == n2) {
			i--;
			j--;
			if (version1[i] != version2[j]) {
				return version1[i] > version2[j] ? 1 : -1;
			}
			return 0;
		}
		if (i < n1) {
			i--;
			j--;
			if (version1[i] != version2[j]) {
				if (version1[i] == '0') {
					while (i < n1&&version1[i] == '0')i++;
					if (i == n1 || version1[i] == '.') {
						if (!flag)return -1;
						else return 1;
					}
					if (i == n1 - 1 && version1[i] < version2[j]) {
						if (!flag)return -1;
						else return 1;
					}
					if (i < n1 - 1 && version1[i] < version2[j] && version1[i] == '.') {
						if (!flag)return -1;
						else return 1;
					}
					if (version1[i] != version2[j]) {
						if (version1[i] > version2[j]) {
							if (!flag)return 1;
							else return -1;
						}
						else {
							if (!flag)return 1;
							else return -1;
						}
					}
					else {
						if (++i < n1) {
							if (version1[++i] != '.') {
								if (!flag)return 1;
								else return -1;
							}
						}
						while (++i < n1)
						{
							if (version1[i] != '0'&&version1[i] != '.') {
								if (!flag)return 1;
								else return -1;
							}
						}
					}
				}
				else {
					if (version1[i + 1] == '.') {
						if (!flag)return -1;
						else return 1;
					}
					else {
						if (!flag)return 1;
						else return -1;
					}
				}
			}
			else {
				if (version1[++i] != '.') {
					if (!flag)return 1;
					else return -1;
				}
				while (++i< n1)
				{
					if (version1[i] != '0'&&version1[i] != '.') {
						if (!flag)return 1;
						else return -1;
					}
				}
			}
		}
		return 0;
	}*/
	int compareVersion(string version1, string version2) {
		int n1 = version1.length();
		int n2 = version2.length();
		string v1, v2;
		int i = 0, j = 0;
		while (i<n1||j<n2)
		{
			int d1 = 0, d2 = 0;
			while (i<n1&&version1[i]!='.')
			{
				v1 += version1[i];
				i++;
			}
			d1 = atoi(v1.c_str());
			while (j<n2&&version2[j]!='.')
			{
				v2 += version2[j];
				j++;
			}
			d2 = atoi(v2.c_str());
			if (d1 > d2)return 1;
			if (d1 < d2)return -1;
			i++;
			j++;
			v1.clear();
			v2.clear();
		}
		return 0;
	}
};
int main()
{
	//1.9.9.9 1.10.0.0
	/*string v1 = "0.1";
	string v2 = "0.0.1";*/
	string v1 = "1.1";
	string v2 = "1.000000000000000000000010";
	cout << Solution().compareVersion(v1, v2);
    //std::cout << "Hello World!\n"; 
}
// 1.2 1.10
// 1.2 1.10.1  //1.02 1.0022
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
//比较两个版本号 version1 和 version2。
//如果 version1  > version2 返回 1，如果 version1  < version2 返回 - 1， 除此之外返回 0。
//
//	你可以假设版本字符串非空，并且只包含数字和 .字符。
//
//	.字符不代表小数点，而是用于分隔数字序列。
//
//	例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。
//
//	你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）和第二级（小版本）修订号分别为 3 和 4。其第三级和第四级修订号均为 0。
//
//
//	示例 1 :
//
//输入: version1 = "0.1", version2 = "1.1"
//	输出 : -1
//	示例 2 :
//
//	输入 : version1 = "1.0.1", version2 = "1"
//	输出 : 1
//	示例 3 :
//
//	输入 : version1 = "7.5.2.4", version2 = "7.5.3"
//	输出 : -1
//	示例 4：
//
//	输入：version1 = "1.01", version2 = "1.001"
//	输出：0
//	解释：忽略前导零，“01” 和 “001” 表示相同的数字 “1”。
//	示例 5：
//
//	输入：version1 = "1.0", version2 = "1.0.0"
//	输出：0
//	解释：version1 没有第三级修订号，这意味着它的第三级修订号默认为 “0”。
//
//
//	提示：
//
//	版本字符串由以点 （.） 分隔的数字字符串组成。这个数字字符串可能有前导零。
//	版本字符串不以点开始或结束，并且其中不会有两个连续的点。
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/compare-version-numbers
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。