#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000;
int n, m, p, a[maxn + 5];
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
            set<int> unique;
            for (int k = 0; k <= i - 1; k++)
                if (unique.find(dp[i - k - 1][j - 1] % p) == unique.end())
                {
                    dp[i][j] = max(dp[i][j], (sum[i] - sum[i - k - 1]) % p + dp[i - k - 1][j - 1]);
                    unique.insert(dp[i - k - 1][j - 1] % p);
                }
        }
    printf("%d\n", dp[n][m]);
    return 0;
}