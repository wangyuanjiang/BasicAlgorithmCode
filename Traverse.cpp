#include<iostream>

#include<vector>
#include<queue>
using namespace std;
typedef char VertexType;  //顶点类型
typedef int EdgeType;// 边上的权值类型
#define MAXVEX 100 //最大顶点数
#define INFINTY 65545//用65535来代表无穷

bool visit_dfs[MAXVEX];
struct MGraph {

	VertexType vexs[MAXVEX];	//顶点表
	EdgeType arc[MAXVEX][MAXVEX];	//	邻接矩阵
	int numVertexes, numEdges;		//	顶点数和边数

};

void BFSTraverse(MGraph &G) {
	queue<decltype (G.vexs[0])> Q;
	queue<int> h;
	vector<bool> visit(G.numVertexes, 0);
	int i, j,k;
	for (i = 0; i < G.numVertexes; i++) {
		if (!visit[i]) {
			Q.push(G.vexs[i]);
			//cout << G.vex[i];
			visit[i] = 1;
			h.push(i);
		}
		while (!Q.empty()) {
			decltype (G.vexs[0]) front = Q.front();
			Q.pop();
			cout << front << endl;   
			k = h.front();
			h.pop();

			for(j=0;j<G.numVertexes;j++)
				if (G.arc[k][j] == 1 && !visit[j]) {
				
					Q.push(G.vexs[j]);
					h.push(j);
					visit[j] = 1;
				}
		}
	}
}

//vector<bool>visited(G.numVertexes, 0);

void DFStraverse(MGraph& G) {
	//int i = 0;
	//vector<bool>visited(G.numVertexes, 0);
	for (int i = 0; i < G.numVertexes; i++)
		visit_dfs[i] = false;	//初始化访问标志数组

	for (int i = 0; i < G.numVertexes; i++)
		if(!visit_dfs[i] )      //对未访问的顶点调用DFS
		DFS(G, i);
}

void DFS(MGraph& G, int i)        //深度遍历递归操作
{
	int j;
	//vector<bool>visited(G.numVertexes, 0);
	visit_dfs[i] = true;
	cout << G.vexs[i];

	for (j = 0; j < G.numVertexes; j++) {
		if (!visit_dfs[j] && G.arc[i][j])	//对未访问邻接顶点递归调用
			DFS(G, j);
	}
}