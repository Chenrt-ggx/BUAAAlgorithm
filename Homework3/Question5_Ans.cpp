#include <queue>
#include <cstdio>
#include <vector>
using namespace std;

inline bool check(int x, int y, int n, int m, vector<vector<bool>> vis)
{
    if (x < 0 || x >= n)
        return false;
    if (y < 0 || y >= m)
        return false;
    return !vis[x][y];
}

inline void display(vector<vector<int>> map)
{
    for (vector<int> i : map)
    {
        for (int j : i)
            printf("%02d ", j);
        putchar('\n');
    }
    return;
}

inline void search(int x, int y, int n, int m, vector<vector<int>> map, vector<vector<int>> &ans)
{
    static int next[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vis[x][y] = true;
    queue<pair<int, int>> que;
    que.push(pair<int, int>(x, y));
    while (!que.empty())
    {
        pair<int, int> node = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int new_x = node.first + next[i][0];
            int new_y = node.second + next[i][1];
            if (check(new_x, new_y, n, m, vis))
            {
                vis[new_x][new_y] = true;
                ans[new_x][new_y] = ans[node.first][node.second] + 1;
                if (!map[new_x][new_y])
                    que.push(pair<int, int>(new_x, new_y));
            }
        }
    }
    return;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> blocks;
    vector<vector<int>> map(n, vector<int>(m, 0));
    for (int i = 0, val; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &val);
            map[i][j] = val;
            if (val)
                blocks.push_back(pair<int, int>(i, j));
        }
    vector<vector<int>> from_end(n, vector<int>(m, 0));
    vector<vector<int>> from_begin(n, vector<int>(m, 0));
    search(0, 0, n, m, map, from_begin);
    search(n - 1, m - 1, n, m, map, from_end);
    // putchar('\n'),display(from_begin);
    // putchar('\n'),display(from_end);
    int ans = from_begin[n - 1][m - 1];
    for (pair<int, int> i : blocks)
        ans = min(ans, from_begin[i.first][i.second] + from_end[i.first][i.second]);
    printf("%d\n", ans);
    return 0;
}