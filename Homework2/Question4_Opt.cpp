#include <cstdio>
using namespace std;

const int maxn=1000;
int n,m,a[maxn+5];
int dp[maxn+5][maxn+5];

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<=n;i++) dp[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			dp[i][j]=dp[i][j-1]+dp[i-1][j]-((a[i]>=j)?0:dp[i-1][j-1-a[i]]);
	printf("%d\n",dp[n][m]);
	return 0;
}