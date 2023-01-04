#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,ans=0; scanf("%d %d",&n,&m);
	vector<int> v(n); for (int i=0;i<n;i++) scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	int lptr=0,rptr=n-1;
	while (lptr<=rptr) lptr+=v[lptr]+v[rptr]<=m,rptr--,ans++;
	printf("%d\n",ans); return 0;
}