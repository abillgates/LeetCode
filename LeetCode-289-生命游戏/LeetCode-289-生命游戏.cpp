// LeetCode-289-生命游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void gameOfLife0(vector<vector<int>>& board) {
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> flag(m, vector<bool>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int good = 0;
				int bad = 0;
				if (i - 1 >= 0&&board[i - 1][j] == 1)
					good++;
				else
					bad++;
				if (i - 1 >= 0&&j - 1 >= 0&&board[i - 1][j - 1] == 1)
					good++;
				else
					bad++;
				if (j - 1 >= 0&&board[i][j - 1] == 1)
					good++;
				else
					bad++;
				if (i - 1 >= 0&&j + 1 < n&&board[i - 1][j + 1] == 1)
					good++;
				else
					bad++;
				if (j + 1 < n&&board[i][j + 1] == 1)
					good++;
				else
					bad++;
				if (i + 1 < m&&board[i + 1][j] == 1) 				
					good++;
				else
					bad++;
				if (i + 1 < m&&j + 1 < n&&board[i + 1][j + 1] == 1)
					good++;
				else
					bad++;
				if (i + 1 < m&&j - 1 >= 0 && board[i + 1][j - 1] == 1)
					good++;
				else
					bad++;				
				if (board[i][j] == 1) {
					if (good < 2)
						flag[i][j] = false;
					if (good == 2 || good == 3)
						flag[i][j] = true;
					if (good > 3)
						flag[i][j] = false;
				}
				else {
					if (good == 3)
						flag[i][j] = true;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (flag[i][j])
					board[i][j] = 1;
				else
					board[i][j] = 0;
			}
		}
	}
	void gameOfLife(vector<vector<int>>& board) {
		int m = board.size();
		int n = board[0].size();
		int x[] = { -1,-1,-1,0,0,1,1,1 };
		int y[] = { -1,0,1,-1,1,-1,0,1 };
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int dx = i + x[k];
					int dy = j + y[k];
					if (dx >= 0 && dx < m&&dy >= 0 && dy < n && (board[dx][dy] == 1 || board[dx][dy] == 2))
						cnt++;
				}
				if (board[i][j] == 1 && (cnt > 3||cnt<2))
					board[i][j] = 2;
				if (!board[i][j] && cnt == 3)
					board[i][j] = 3;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = board[i][j] % 2;
			}
		}
	}
private:
	enum status
	{
		live = 2,
		unlive = -1
	};
};
int main()
{
	Solution s;
	vector<vector<int>> board{
		{0,1,0},
		{0,0,1},
		{1,1,1},
		{0,0,0}
	};
	/*vector<vector<int>> board{
		{1,1},
		{1,0}
	};*/
	s.gameOfLife(board);
	for (auto i : board) {
		for (int j : i) {
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
//根据百度百科，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在1970年发明的细胞自动机。
//
//给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞具有一个初始状态 live（1）即为活细胞， 或 dead（0）即为死细胞。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
//
//如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
//根据当前状态，写一个函数来计算面板上细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
//
//示例 :
//
//输入:
//[
//	[0, 1, 0],
//	[0, 0, 1],
//	[1, 1, 1],
//	[0, 0, 0]
//]
//输出:
//  [
//	  [0, 0, 0],
//	  [1, 0, 1],
//	  [0, 1, 1],
//	  [0, 1, 0]
//  ]
//  进阶:
//
//	你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
//		本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
//
//		来源：力扣（LeetCode）
//		链接：https ://leetcode-cn.com/problems/game-of-life
//	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。