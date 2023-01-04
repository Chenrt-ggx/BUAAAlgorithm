#include <cstdio>
#include <vector>
using namespace std;

int a[10005];
int tot, fst[10005], nxt[10005], val[10005];

void build(int l, int r)
{
    nxt[++tot] = fst[r - l + 1], fst[r - l + 1] = tot;
    int mid = (l + r) >> 1;
    val[tot] = mid;
    if (r >= mid + 1)
        build(mid + 1, r);
    if (mid - 1 >= l)
        build(l, mid - 1);
    return;
}

int main()
{
    int n, cnt = 0;
    freopen("testcase.txt", "r", stdin);
    scanf("%d", &n);
    build(0, n - 1);
    for (int i = n; i > 0; i--)
        for (int j = fst[i]; j; j = nxt[j])
            a[val[j]] = ++cnt;
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);
    bool isRight = true;
    for (int i = 0, std; i < n; i++)
    {
        scanf("%d", &std);
        if (a[i] != std)
            isRight = false;
    }
    printf(isRight ? "AC\n" : "WA\n");
    return 0;
}