
#include "JZOff.h"

class Solution {  
public:
	bool exist(vector<vector<char>>& board, string word) {

		int rows = board.size();

		int cols = board[0].size();

		if (rows * cols < word.size() || word.size() == 0) return false;

		vector<vector<bool>> flag(rows, vector<bool>(cols, 0));
		
		int strLen = 0;
		for (int row = 0; row < rows; row++)
			for (int col = 0; col < cols; col++)
				if (backtrack(board, word, flag, strLen, rows, cols, row, col))
					return true;

		return false;
	}

	bool backtrack(vector<vector<char>>& board, string word, vector<vector<bool>>& flag, int& strLen, int rows, int cols, int row, int col)
	{
		if (strLen == word.size()) return true;

		bool hasPath = false;

		if (row >= 0 && row < rows && col >= 0 && col < cols && !flag[row][col] && word[strLen] == board[row][col]) {

			strLen++;
			flag[row][col] = true;

			hasPath = backtrack(board, word, flag, strLen, rows, cols, row + 1, col)
				|| backtrack(board, word, flag, strLen, rows, cols, row - 1, col)
				|| backtrack(board, word, flag, strLen, rows, cols, row, col - 1)
				|| backtrack(board, word, flag, strLen, rows, cols, row, col + 1);


			if (!hasPath) {
				strLen--;
				flag[row][col] = false;
			}
		}
		return hasPath;
	}
};

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty())
			return word.empty();
		for (int row = 0; row < board.size(); ++row) {
			for (int col = 0; col < board[0].size(); ++col) {
				if (backtrack(board, row, col, word, 0)) return true;
			}
		}

		return false;
	}
private:
	bool backtrack(vector<vector<char>> &board, int row, int col,
		const string &word, int idx) {
		if (idx == word.size()) return true;
		if (row < 0 || row >= board.size() ||
			col < 0 || col >= board[0].size()) return false;
		if (word[idx] != board[row][col]) return false;

		board[row][col] = '*';
		if (backtrack(board, row - 1, col, word, idx + 1) ||
			backtrack(board, row + 1, col, word, idx + 1) ||
			backtrack(board, row, col - 1, word, idx + 1) ||
			backtrack(board, row, col + 1, word, idx + 1))
			return true;

		board[row][col] = word[idx];
		return false;
	}
};

class Solution {	//更简洁 和一般的回溯的区别是 这里只不过是两重循环；
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty())
			return word.empty();
		vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), 0));
		for (int row = 0; row < board.size(); ++row) {	//二维数组，所以要两重循环
			for (int col = 0; col < board[0].size(); ++col) {
				if (backtrack(board, used, row, col, word, 0)) return true;
			}
		}

		return false;
	}
	bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& used, int row, int col, string& word, int index) {
				
		if (index == word.size())    return true;

		if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && !used[row][col] && word[index] == board[row][col]) {

			used[row][col] = true;

			if (	backtrack(board, used, row - 1, col, word, index + 1)	//上

				|| backtrack(board, used, row + 1, col, word, index + 1)//下
				|| backtrack(board, used, row, col - 1, word, index + 1)//左
				|| backtrack(board, used, row, col + 1, word, index + 1))//右
				return true;
			
			used[row][col] = false; //状态重置
		}
		return false;

	}

};