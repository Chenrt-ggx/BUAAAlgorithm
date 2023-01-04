#include <cstdio>

const int maxn = 1000;
double sum, src[maxn + 5];

inline int countbit(int num)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
        if (num & (1 << i))
            ans++;
    return ans;
}

inline void cal(int num)
{
    double p = 1;
    for (int i = 0; i < 32; i++)
        if (num & (1 << i))
            p *= src[i];
        else
            p *= 1 - src[i];
    sum += p;
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &src[i]);
    for (int i = 0; i < 1 << n; i++)
        if (countbit(i) > n / 2)
            cal(i);
    printf("%lf\n", sum);
    return 0;
}