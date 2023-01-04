#include <cstdio>
#include <vector>
using namespace std;

const int inf=100000000;

int main()
{
	int n,ans=inf; scanf("%d",&n);
	vector<vector<int>> dis(n,vector<int>(n,0));
	vector<vector<int>> graph(n,vector<int>(n,0));
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",&graph[i][j]);
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) dis[i][j]=graph[i][j];
	for (int k=0;k<n;k++) for (int i=0;i<n;i++) for (int j=0;j<n;j++)
	{
		if (i<j && j<k) ans=min(ans,dis[i][j]+graph[i][k]+graph[j][k]);
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	if (ans<inf) printf("%d\n",ans);
	else puts("nan");
	return 0;
}