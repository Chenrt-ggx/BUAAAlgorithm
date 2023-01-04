#include <cstdio>

const int maxn=1000;
int n,a[maxn+5],dp[maxn+5],last[maxn+5];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),dp[i]=1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<i;j++)
            if (a[i]>a[j] && dp[j]+1>=dp[i])
                dp[i]=dp[j]+1,last[i]=j;
    int ans=-1,idx=-1,tot=0;
    for (int i=1;i<=n;i++) if (dp[i]>ans) ans=dp[i],idx=i;
    while (idx) dp[tot++]=a[idx],idx=last[idx];
    printf("%d\n",ans);
    for (int i=tot-1;i>=0;i--) printf("%d ",dp[i]);
    puts(""); return 0;
}