#include <set>
#include <cstdio>
#include <random>
#include <utility>
using namespace std;

mt19937 generator(0x19260817);

int main()
{
    int n=15000,m=60000;
    printf("%d %d\n",n,m);
    set<pair<int,int>> unique;
    for (int i=0;i<m;i++)
    {
        int x=generator()%n;
        int y=generator()%n;
        pair<int,int> gen(x,y);
        if (unique.find(gen)!=unique.end()) {i--; continue;}
        printf("%d %d\n",x,y);
    }
    return 0;
}