#include <cstdio>
#include <random>
using namespace std;

mt19937 generator(0x19260817);

int main()
{
    const int n=1000;
    printf("%d\n",n);
    for (int i=0;i<n;i++)
    printf("%d\n",generator()%100);
    return 0;
}