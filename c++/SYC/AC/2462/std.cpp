#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w, net;
} e[800005];
int n, m, head[200005], pos, u, v, w;
void addEdge(int u, int v, int w)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
bool vis[200005];
int bfs(int x)
{
    deque<pair<int, int>> q;
    q.push_back({x, 0});
    while (!q.empty())
    {
        auto u = q.front();
        // printf("to:%d\n", u.first);
        q.pop_front();
        if (vis[u.first])
            continue;
        vis[u.first] = true;
        if (u.first == n)
            return u.second;
        for (int i = head[u.first]; i; i = e[i].net)
        {
            int v = e[i].v;
            if (!vis[v])
            {
                // printf("vis[%d]:", v);
                if (e[i].w == 1)
                    q.push_back({v, u.second + 1});
                else
                    q.push_front({v, u.second});
            }
        }
    }
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    printf("%d", bfs(1));
    return 0;
}