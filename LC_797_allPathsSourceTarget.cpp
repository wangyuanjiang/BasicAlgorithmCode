#include <iostream>
#include<vector>
#include<set>
using namespace std;
class solusion {//  ���ݷ���

public:
	vector<vector<int>> vec;
	vector<int> tem;
	//////////////////////////////////////////////////////////////////////////////////////////////////////���ݷ�
	void dfs(vector<vector<int>>& grap, int cur) {
		if (cur == grap.size() - 1) {
			vec.push_back(tem);
			return;
		}
		for (size_t i = 0; i < grap[cur].size(); i++) {
			tem.push_back(grap[cur][i]);
			dfs(grap, grap[cur][i]); 
			tem.pop_back();//Ϊɶֻpopһ�Σ�dfs(grap,0)->dfs(grap,1)->   dfs(grap,3), ->   ���ؿ���Ȩ��dfs(grap,1), ��i=1ʱ������ѭ����dfs(grap,1)ִ�н��������ؿ���Ȩ��dfs(grap,0)��ʱi=0��dfs(grap,0)�Ѿ�ִ����dfs(grap,1)�ĵݹ���ã�����ִ��tem.pop()��䣬Ȼ��i++���ݹ����dfs(grap,2)�ݹ����dfs(grap,3)
			                          //   tem=[1]->     tem=[1,3]-> vec={[1,3]},           ->tem=[1],i++;                                                                                                                        ->tem=[];                   ->tem=[2];             ->tem=[2,3];
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		tem.push_back(0);
		dfs(graph, 0);
		return vec;
	}
}; 