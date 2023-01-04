#include <stack>
#include <cstdio>
#include <vector>
using namespace std;

int n, m, count, colors;
vector<vector<int>> graph;

stack<int> stk;
vector<bool> vis;
vector<int> dfn, low, color;

void tarjan(int src)
{
    dfn[src] = low[src] = ++count;
    vis[src] = true, stk.push(src);
    for (int i : graph[src])
    {
        if (!dfn[i])
            tarjan(i), low[src] = min(low[src], low[i]);
        else if (vis[i])
            low[src] = min(low[src], dfn[i]);
    }
    if (dfn[src] == low[src])
    {
        vis[src] = false, color[src] = colors;
        while (!stk.empty() && stk.top() != src)
        {
            color[stk.top()] = colors;
            vis[stk.top()] = false;
            stk.pop();
        }
        colors++, stk.pop();
    }
}

int main()
{
    int ans = 0;
    scanf("%d %d", &n, &m);
    graph.resize(n), vis.resize(n, false);
    dfn.resize(n, 0), low.resize(n, 0), color.resize(n, 0);
    for (int s, t, i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &t);
        graph[s].push_back(t);
    }
    for (int i = 0; i < n; i++)
        if (!dfn[i])
            tarjan(i);
    vector<int> check(colors, 0);
    for (int i = 0; i < n; i++)
        for (int j : graph[i])
            if (color[i] - color[j])
                check[color[j]]++;
    for (int i : check)
        if (!i)
            ans++;
    printf("%d\n", ans);
    return 0;
}