#include <iostream>
#include <vector>
#include <iomanip> //���Ƹ������ľ���
#include  <string>
#include <algorithm>
//#include <unordered_map>
#include <set>
using namespace std;

/*�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ����е�����һ��ʼ��
ÿһ�������ھ����������ҡ��ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���ø��ӡ�
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

		bool hasPath = false;//���һ��bool����
		if (row >=0 && row < board.size() && col >= 0 && col < board[0].size())
		{
			if (!used[row][col] && word[strLen] == board[row][col]) {	//��word[0]��ʼ�Ƚ�

				strLen ++;
				used[row][col] = true;

				hasPath = backtrack(board, word,   used,   strLen, row - 1, col)
					|| backtrack(board, word,  used, strLen, row + 1, col)
					|| backtrack(board, word,  used, strLen, row, col - 1)
					|| backtrack(board, word,  used, strLen, row, col + 1);


				if (!hasPath) {	//�߲�ͨ��״̬����
					strLen--;
					used[row][col] = false;
				}
			}
		}

		return hasPath;
		
	}
	

};