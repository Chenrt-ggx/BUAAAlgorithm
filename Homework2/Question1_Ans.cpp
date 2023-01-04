#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10000;
int dp[maxn + 5][3], n, l, r;

inline int cal(int mod, int num)
{
    int ans = num / 3;
    if (num % 3 == 1 && mod == 1)
        ans++;
    if (num % 3 == 2 && mod >= 1)
        ans++;
    return ans;
}

inline int init(int mod)
{
    int gap = max(max(l, r), max(-l, -r)) / 3 * 3 + 3;
    return cal(mod, r + gap) - cal(mod, l - 1 + gap);
}

int main()
{
    while (~scanf("%d %d %d", &n, &l, &r))
    {
        if (l > r)
        {
            puts("0");
            continue;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 3; i++)
            dp[0][i] = init(i);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    dp[i][j] += dp[i - 1][k] * dp[0][(j - k + 3) % 3];
        printf("%d\n", dp[n - 1][0]);
    }
    return 0;
}