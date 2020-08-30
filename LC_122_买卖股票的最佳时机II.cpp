#include<iostream>
//include<algorithm>
#include<vector>
using namespace std;

/*���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����

ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����*/


//-------------------------������-------------------
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		return calculate(prices, 0);
	}

	int calculate(vector<int>& prices, int s) {
		if (s >= prices.size())
			return 0;
		int max = 0;
		for (int start = s; start < prices.size(); start++) {
			int maxprofit = 0;
			for (int i = start + 1; i < prices.size(); i++) {
				if (prices[start] < prices[i]) {
					int profit = calculate(prices, i + 1) + prices[i] - prices[start];// �ݹ�n^n �� ���Ӷ�ΪO(n^n)
					if (profit > maxprofit)
						maxprofit = profit;
				}
			}
			if (maxprofit > max)
				max = maxprofit;
		}
		return max;
	}


};

//--------------------��ȷ�---�ؼ���������Ҫ���ǵ������ȵ�ÿһ����ֵ������������������ͼ��������һ����ֵ����ȡ��������
//                            ��ô�������ս�ʧȥ����һ�ʽ����л�õ����󣬴Ӷ�����������Ľ��͡�

class Solution {
public: int maxProfit(vector<int>& prices) {
		int i = 0;
		int valley = prices[0];
		int peak = prices[0];
		int maxprofit = 0;
		while (i < prices.size() - 1) {
			while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
				i++;
			valley = prices[i]; // ��
			while (i < prices.size()- 1 && prices[i] <= prices[i + 1])
				i++;
			peak = prices[i];	//��
			maxprofit += peak - valley;
		}
		return maxprofit;
	}
};

//--------------------------��һ�α���
// 1 5 7 8 profit= 5-1+ 7-5+ 8-7 = 8-1 =7; ֻҪ����һ����ǰ��һ����ͼ����ֵ
int maxProfit(vector<int>& prices) {
	int totalProfite = 0;
	for (size_t i = 1; i < prices.size(); i++)
	{
		if (prices[i - 1] < prices[i])
			totalProfite += (prices[i] - prices[i - 1]);
	}
	return totalProfite;
}


