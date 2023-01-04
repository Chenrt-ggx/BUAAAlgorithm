#include <cmath>
#include <cstdio>

inline int cal(int num)
{
    if (num == 0)
        return 0;
    int ans = (num + 1) * num >> 1;
    int top = int(log(num) / log(2));
    for (int i = 1; i <= top; i++)
        ans -= ((num >> i) + 1) * (num >> i) >> 1;
    return ans;
}

int main()
{
    int l, r, ans = 0;
    freopen("testcase.txt", "r", stdin);
    scanf("%d %d", &l, &r);
    if (l > r)
        ans = 0;
    else if (l < 0 && r < 0)
        ans = cal(-r - 1) - cal(-l);
    else if (l >= 0 && r >= 0)
        ans = cal(r) - cal(l - 1);
    else if (l < 0 && r >= 0)
        ans = cal(r) - cal(-l);
    printf("%d\n", ans);
    int std;
    scanf("%d", &std);
    printf(ans == std ? "AC\n" : "WA\n");
    return 0;
}