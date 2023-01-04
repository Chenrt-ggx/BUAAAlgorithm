#include <cstdio>
using namespace std;

int ans=0,select[10];

void dfs(int cur,int tot,int l,int r)
{
    if (cur==tot)
    {
        int sum=0;
        for (int i=0;i<tot;i++) sum+=select[i];
        ans+=sum%3==0;
        return;
    }
    for (int i=l;i<=r;i++)
    select[cur]=i,dfs(cur+1,tot,l,r);
    return;
}

int main()
{
    int n,l,r;
    while (~scanf("%d %d %d",&n,&l,&r))
    {
        ans=0,dfs(0,n,l,r);
        printf("%d\n",ans);
    }
    return 0;
}