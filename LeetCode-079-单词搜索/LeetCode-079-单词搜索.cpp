// LeetCode-079-单词搜索.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> memo(m,vector<bool>(n,false));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (search(board, word, 0, i, j,memo)) {
					return true;
				}
			}
		}
		return false;	
	}
	bool search(vector<vector<char>>& board, string word, int index, int i, int j) {
		int m = board.size();
		int n = board[0].size();
		if (index == word.length()) {
			return true;
		}
		bool res = false;
		if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
			return res;
		}
		char c = board[i][j];
		board[i][j] = '#';
		res = search(board, word, index + 1, i, j + 1) || search(board, word, index + 1, i + 1, j)
			|| search(board, word, index + 1, i, j - 1) || search(board, word, index + 1, i - 1, j);
		board[i][j] = c;			
		return res;
	}
	bool search(const vector<vector<char>>& board, const string word, int index, int i, int j, vector<vector<bool>>& memo) {
		int m = board.size();
		int n = board[0].size();
		if (index == word.length()) {
			return true;
		}
		bool res=false;
		if (i < 0 || i >= m || j < 0 || j >= n) {
			return false;
		}
		if (!memo[i][j]) {
			if (board[i][j] != word[index]) {
				return false;
			}
			memo[i][j] = true;
			res = search(board, word, index + 1, i, j + 1, memo) || search(board, word, index + 1, i + 1, j, memo)
				|| search(board, word, index + 1, i, j - 1, memo) || search(board, word, index + 1, i - 1, j, memo);
			memo[i][j] = false;
		}
		return res;
	}
};
int main()
{
	vector<vector<char>> board{
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	string word = "ABCCEDFSA";
	cout << Solution().exist(board, word);
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
//给定一个二维网格和一个单词，找出该单词是否存在于网格中。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//示例 :
//
//board =
//[
//	['A', 'B', 'C', 'E'],
//	['S', 'F', 'C', 'S'],
//	['A', 'D', 'E', 'E']
//]
//
//给定 word = "ABCCED", 返回 true.
//给定 word = "SEE", 返回 true.
//给定 word = "ABCB", 返回 false.
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/word-search
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。