#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000;
int matrix[3][3], cnt[3], n, l, r;

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

void mulCount()
{
    int tmp[3];
    for (int i = 0; i < 3; i++)
        tmp[i] = cnt[i], cnt[i] = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cnt[j] += matrix[i][j] * tmp[i];
    return;
}

void mulMatrix()
{
    int tmp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tmp[i][j] = matrix[i][j], matrix[i][j] = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                matrix[i][j] += tmp[i][k] * tmp[k][j];
    return;
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
        for (int i = 0; i < 3; i++)
            cnt[i] = init(i);
        matrix[0][0] = cnt[0], matrix[0][1] = cnt[1], matrix[0][2] = cnt[2];
        matrix[1][0] = cnt[2], matrix[1][1] = cnt[0], matrix[1][2] = cnt[1];
        matrix[2][0] = cnt[1], matrix[2][1] = cnt[2], matrix[2][2] = cnt[0];
        for (int t = n - 1; t; t >>= 1)
        {
            if (t & 1)
                mulCount();
            mulMatrix();
        }
        printf("%d\n", cnt[0]);
    }
    return 0;
}