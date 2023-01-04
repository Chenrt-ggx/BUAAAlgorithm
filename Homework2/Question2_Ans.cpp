#include <cstdio>

const int maxn=1000;
int n,a[maxn+5],dp[maxn+5],last[maxn+5];

int main()
{
	scanf("%d",&n);
	int ans=-1,idx=-1,tot=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=0x7fffffff;
	for (int i=1,l,r;i<=n;i++)
	{
		for (l=0,r=n+1;r-l>1;)
		{
			int mid=(l+r)>>1;
			if (a[dp[mid]]>=a[i]) r=mid;
			else l=mid;
		}
		dp[r]=i,last[i]=dp[r-1];
		if (r>ans) ans=r,idx=i;
	}
	while (idx) dp[tot++]=a[idx],idx=last[idx];
	printf("%d\n",ans);
	for (int i=tot-1;i>=0;i--) printf("%d ",dp[i]);
	puts(""); return 0;
}