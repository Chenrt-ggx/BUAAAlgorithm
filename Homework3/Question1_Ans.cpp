#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n,x,ans=0; scanf("%d %d",&n,&x);
	vector<int> a(n); for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) if (a[i-1]+a[i]>=x)
	{
		int gap=a[i-1]+a[i]-x+1;
		if (gap<=a[i]) a[i]-=gap;
		else a[i-1]-=gap-a[i],a[i]=0;
		ans+=gap;
	}
	printf("%d\n",ans);
	return 0;
}