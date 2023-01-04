#include <cstdio>
#include <random>
#include <algorithm>
using namespace std;

mt19937 generator(19260817);

int main()
{
	const int n=1000;
	printf("%d %d %d\n",n,generator()%(n>>1)+(n>>1),generator()%(n>>2)+(n>>3));
	for (int i=0;i<n;i++) printf("%d\n",generator()%(n<<5));
	return 0;
}