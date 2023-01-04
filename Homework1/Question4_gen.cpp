#include <cstdio>
#include <random>
#include <algorithm>
using namespace std;

mt19937 generator(0x19260817);

int main()
{
    int n = 10000;
    freopen("testcase.txt", "w", stdout);
    int l = generator() % n - (n >> 1), r = generator() % n - (n >> 1);
    if (l > r)
        swap(l, r);
    printf("%d %d\n", l, r);
    int ans = 0;
    for (int i = l; i <= r; i++)
        ans += i ? i / (i & -i) : 0;
    printf("%d\n", ans);
    return 0;
}