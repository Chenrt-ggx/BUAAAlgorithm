#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n,k,ans; scanf("%d %d",&n,&k);
    vector<int> a(n); for (int i=0;i<n;i++) scanf("%d",&a[i]);
    if (k==1) {ans=0x7fffffff; for (int i=0;i<n;i++) ans=min(ans,a[i]);}
    else if (k!=2) {ans=0x80000000; for (int i=0;i<n;i++) ans=max(ans,a[i]);}
    else
    {
        vector<int> lmin(n),rmin(n);
        lmin[0]=a[0],rmin[n-1]=a[n-1],ans=0x80000000;
        for (int i=1;i<n;i++) lmin[i]=min(lmin[i-1],a[i]);
        for (int i=n-2;i>=0;i--) rmin[i]=min(rmin[i+1],a[i]);
        for (int i=1;i<n;i++) ans=max(ans,max(lmin[i-1],rmin[i]));
    }
    printf("%d\n",ans);
    return 0;
}