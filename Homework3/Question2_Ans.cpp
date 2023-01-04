#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> a(n);
    for (int i = 0, val; i < n; i++)
        scanf("%d", &val), a[i].first = val, a[i].second = i + 1;
    sort(a.begin(), a.end(), [](pair<int, int> x, pair<int, int> y)
        { return x.first < y.first; });
    for (int i = 0; i < n; i++)
        printf("%d ", a[i].second);
    putchar('\n');
    return 0;
}