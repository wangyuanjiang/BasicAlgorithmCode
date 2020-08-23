#include<iostream>

#include<vector>
#include<queue>
using namespace std;
typedef char VertexType;  //��������
typedef int EdgeType;// ���ϵ�Ȩֵ����
#define MAXVEX 100 //��󶥵���
#define INFINTY 65545//��65535����������

bool visit_dfs[MAXVEX];
struct MGraph {

	VertexType vexs[MAXVEX];	//�����
	EdgeType arc[MAXVEX][MAXVEX];	//	�ڽӾ���
	int numVertexes, numEdges;		//	�������ͱ���

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
		visit_dfs[i] = false;	//��ʼ�����ʱ�־����

	for (int i = 0; i < G.numVertexes; i++)
		if(!visit_dfs[i] )      //��δ���ʵĶ������DFS
		DFS(G, i);
}

void DFS(MGraph& G, int i)        //��ȱ����ݹ����
{
	int j;
	//vector<bool>visited(G.numVertexes, 0);
	visit_dfs[i] = true;
	cout << G.vexs[i];

	for (j = 0; j < G.numVertexes; j++) {
		if (!visit_dfs[j] && G.arc[i][j])	//��δ�����ڽӶ���ݹ����
			DFS(G, j);
	}
}