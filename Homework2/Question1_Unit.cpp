#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

inline int cal(int mod,int num)
{
	int ans=num/3;
	if (num%3==1 && mod==1) ans++;
	if (num%3==2 && mod>=1) ans++;
	return ans;
}

inline int init(int l,int r,int mod)
{
	if (l>r) return 0;
	int gap=max(max(l,r),max(-l,-r))/3*3+3;
	return cal(mod,r+gap)-cal(mod,l-1+gap);
}

inline void test(int l,int r)
{
	int ans[3],tst[3];
	for (int i=0;i<3;i++) ans[i]=0;
	for (int i=l;i<=r;i++) ans[(i%3+3)%3]++;
	for (int i=0;i<3;i++) tst[i]=init(l,r,i);
	for (int i=0;i<3;i++) assert (ans[i]==tst[i]);
	return;
}

int main()
{
	for (int i=-20;i<=20;i++)
	for (int j=-20;j<=20;j++)
	test(i,j); return 0;
}