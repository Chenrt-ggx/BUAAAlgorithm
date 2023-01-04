#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000;
int n, m, p, a[maxn + 5];
int last[maxn + 5][maxn + 5];
int sum[maxn + 5], dp[maxn + 5][maxn + 5];

int main()
{
    scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        sum[i] = a[i] + sum[i - 1], dp[i][0] = 0x80000000;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= min(m, i); j++)
        {
            for (int k = 0; k < p; k++)
                dp[i][j] = max(dp[i][j], (sum[i] - sum[last[j - 1][k]]) % p + dp[last[j - 1][k]][j - 1]);
            last[j][dp[i][j] % p] = i;
        }
    printf("%d\n", dp[n][m]);
    return 0;
}