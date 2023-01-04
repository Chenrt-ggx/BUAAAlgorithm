#include <cstdio>
using namespace std;

const int maxn = 20;
int n, m, a[maxn], ans;

inline int C(int k, int n)
{
    if (n < 0)
        return 0;
    long long a = 1, b = 1, c = 1;
    for (int i = 1; i <= n; i++)
        a *= i;
    for (int i = 1; i <= k; i++)
        b *= i;
    for (int i = 1; i <= n - k; i++)
        c *= i;
    return a / b / c;
}

int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < 1 << n; i++)
    {
        int d = n + m, cnt = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                cnt++, d -= a[j + 1];
        if (cnt & 1)
            ans -= C(n - 1, d - cnt - 1);
        else
            ans += C(n - 1, d - cnt - 1);
    }
    printf("%d\n", ans);
    return 0;
}