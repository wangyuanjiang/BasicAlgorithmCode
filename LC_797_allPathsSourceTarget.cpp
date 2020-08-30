#include <iostream>
#include<vector>
#include<set>
using namespace std;
class solusion {//  回溯法；

public:
	vector<vector<int>> vec;
	vector<int> tem;
	//////////////////////////////////////////////////////////////////////////////////////////////////////回溯法
	void dfs(vector<vector<int>>& grap, int cur) {
		if (cur == grap.size() - 1) {
			vec.push_back(tem);
			return;
		}
		for (size_t i = 0; i < grap[cur].size(); i++) {
			tem.push_back(grap[cur][i]);
			dfs(grap, grap[cur][i]); 
			tem.pop_back();//为啥只pop一次？dfs(grap,0)->dfs(grap,1)->   dfs(grap,3), ->   返回控制权给dfs(grap,1), 当i=1时，跳出循环，dfs(grap,1)执行结束，返回控制权给dfs(grap,0)此时i=0；dfs(grap,0)已经执行完dfs(grap,1)的递归调用，现在执行tem.pop()语句，然后i++，递归调用dfs(grap,2)递归调用dfs(grap,3)
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