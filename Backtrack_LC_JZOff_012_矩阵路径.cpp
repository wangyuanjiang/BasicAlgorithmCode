#include <iostream>
#include <vector>
#include <iomanip> //控制浮点数的精度
#include  <string>
#include <algorithm>
//#include <unordered_map>
#include <set>
using namespace std;

/*请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，
每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
*/

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		
		vector<vector<bool> > used(board.size(), vector<bool> (board[0].size(), false));

		int strLen = 0;

		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
				if (backtrack(board, word, used, strLen, i, j))
					return true;

		return false;
	}

	bool backtrack(vector<vector<char>>& board, string word, vector<vector<bool> >& used, int& strLen, int row, int col)
	{
		if (strLen == word.size())
			return  true;

		bool hasPath = false;//标记一个bool变量
		if (row >=0 && row < board.size() && col >= 0 && col < board[0].size())
		{
			if (!used[row][col] && word[strLen] == board[row][col]) {	//从word[0]开始比较

				strLen ++;
				used[row][col] = true;

				hasPath = backtrack(board, word,   used,   strLen, row - 1, col)
					|| backtrack(board, word,  used, strLen, row + 1, col)
					|| backtrack(board, word,  used, strLen, row, col - 1)
					|| backtrack(board, word,  used, strLen, row, col + 1);


				if (!hasPath) {	//走不通再状态重置
					strLen--;
					used[row][col] = false;
				}
			}
		}

		return hasPath;
		
	}
	

};