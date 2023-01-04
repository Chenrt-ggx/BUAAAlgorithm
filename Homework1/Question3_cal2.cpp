#include <cstdio>
#include <vector>
using namespace std;

int a[10005];
vector<int> map[10005];

void build(int l, int r)
{
    int mid = (l + r) >> 1;
    map[r - l + 1].push_back(mid);
    if (mid - 1 >= l)
        build(l, mid - 1);
    if (r >= mid + 1)
        build(mid + 1, r);
    return;
}

int main()
{
    int n, cnt = 0;
    freopen("testcase.txt", "r", stdin);
    scanf("%d", &n);
    build(0, n - 1);
    for (int i = n; i > 0; i--)
        for (int j = 0; j < (int)map[i].size(); j++)
            a[map[i][j]] = ++cnt;
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