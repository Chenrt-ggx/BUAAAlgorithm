#include <queue>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n,m; scanf("%d %d",&n,&m);
	vector<int> dis(n,-1);
	vector<vector<int>> graph(n);
	for (int s,t,i=0;i<m;i++)
	{
		scanf("%d %d",&s,&t);
		graph[s].push_back(t);
		graph[t].push_back(s);
	}
	queue<int> que;
	for (int i=0;i<n;i++) if (dis[i]<0)
	{
		dis[i]=0,que.push(i);
		while (!que.empty())
		{
			int top=que.front(); que.pop();
			for (int j : graph[top])
			{
				if (dis[j]<0) dis[j]=dis[top]+1,que.push(j);
				else if ((~dis[j]^dis[top])&1) {puts("false"); return 0;}
			}
		}
	}
	puts("true");
	return 0;
}