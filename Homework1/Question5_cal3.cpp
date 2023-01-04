#include <cstdio>
#include <cstdlib>

const int bit=25;
const int maxn=10005;
const int inf=100000000;

int cnt=2;
int size[maxn*bit];
int son[maxn*bit][2];
int ans,spl,a[maxn],sum[maxn];

inline int newnode()
{
    son[cnt][0]=son[cnt][1]=size[cnt]=0;
    return cnt++;
}

inline void ins(int num)
{
    for (int i=bit-1,cur=1;i>=0;i--)
    {
        int which=(num>>i)&1;
        if (!son[cur][which]) son[cur][which]=newnode();
        cur=son[cur][which],size[cur]++;
    }
    return;
}

inline int rank(int num)
{
    int ans=0;
    for (int i=bit-1,cur=1;i>=0;i--)
    {
        if ((num>>i)&1) ans+=size[son[cur][0]];
        cur = son[cur][(num>>i)&1];
    }
    return ans;
}

int main()
{
    int n;
    freopen("testcase.txt","r",stdin);
    scanf("%d %d",&n,&spl);
    for (int i=0;i<n;i++) scanf("%d",a+i),sum[i]=a[i];
    for (int i=1;i<n;i++) sum[i]=sum[i-1]+a[i];
    ins(sum[n-1]+inf);
    for (int i=n-2;i>=0;i--)
    {
        ans+=rank(sum[i]+spl+1+inf);
        ins(sum[i]+inf);
    }
    for (int i=0;i<n;i++) ans+=sum[i]<=spl;
    printf("%d\n",ans);
    int std;
    scanf("%d",&std);
    printf(ans==std?"AC\n":"WA\n");
    return 0;
}