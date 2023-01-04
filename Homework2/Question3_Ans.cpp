#include <cstdio>

const int maxn=1000;
double sum,src[maxn+5];
double dp[maxn+5][maxn+5];

int main()
{
	int n; scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&src[i]); dp[0][0]=1;
	for (int i=1;i<=n;i++) dp[i][0]=dp[i-1][0]*(1-src[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dp[i][j]=dp[i-1][j-1]*src[i]+dp[i-1][j]*(1-src[i]);
	for (int i=n/2+1;i<=n;i++) sum+=dp[n][i];
	printf("%lf\n",sum);
	return 0;
}