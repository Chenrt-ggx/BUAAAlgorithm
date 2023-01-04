#include <cstdio>
#include <random>
using namespace std;

int a[10005];
int sum[10005];
mt19937 generator(0x19260817);

inline int cal(int l,int r)
{
    if (l==0) return sum[r];
    return sum[r]-sum[l-1];
}

int main()
{
    freopen("testcase.txt","w",stdout);
    int n=10000,tot=0;
    int spl=generator()%10-5;
    for (int i=0;i<n;i++) sum[i]=a[i]=generator()%n-(n>>1);
    for (int i=1;i<n;i++) sum[i]=a[i]+sum[i-1];
    for (int i=0;i<n;i++) for (int j=i;j<n;j++) tot+=cal(i,j)<=spl;
    printf("%d %d\n",n,spl);
    for (int i=0;i<n;i++) printf("%d\n",a[i]);
    printf("%d\n",tot);
    return 0;
}