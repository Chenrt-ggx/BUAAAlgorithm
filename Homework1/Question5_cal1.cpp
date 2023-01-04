#include <cstdio>

int ans,spl,a[10005],sum[10005],buf[10005];

inline void merge(int l,int mid,int r)
{
    for (int i=l;i<=r;i++) buf[i]=sum[i];
    int i=l,j=mid+1,k=l;
    while (i<=mid || j<=r)
    {
        if (i>mid) sum[k++]=buf[j++];
        else if (j>r) sum[k++]=buf[i++];
        else if (buf[i]>buf[j]) sum[k++]=buf[j++];
        else sum[k++]=buf[i++];
    }
    return;
}

void solve(int l,int r)
{
    if (l==r) return;
    int mid=(l+r)>>1;
    solve(l,mid),solve(mid+1,r);
    // printf("%d %d %d\n",l,mid,r);
    // for (int i=l;i<=mid;i++) printf("%d ",sum[i]); puts("");
    // for (int i=mid+1;i<=r;i++) printf("%d ",sum[i]); puts("");
    for (int lr=mid,rr=r;lr>=l;lr--)
    {
        while (sum[rr]-sum[lr]>spl && rr>mid) rr--;
        if (rr==mid) break;
        ans+=rr-mid;
    }
    merge(l,mid,r); //puts("");
    return;
}

int main()
{
    int n;
    freopen("testcase.txt","r",stdin);
    scanf("%d %d",&n,&spl);
    for (int i=0;i<n;i++) scanf("%d",a+i),sum[i]=a[i];
    for (int i=1;i<n;i++) sum[i]=sum[i-1]+a[i];
    for (int i=0;i<n;i++) ans+=sum[i]<=spl;
    solve(0,n-1);
    printf("%d\n",ans);
    int std;
    scanf("%d",&std);
    printf(ans==std?"AC\n":"WA\n");
    return 0;
}