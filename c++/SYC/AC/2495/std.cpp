#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define d2 "%d%d"
#define d1 "%d"
struct Edge
{
    int u, v, net;
} e[605];
int n, m, head[305], pos, u, v;
void addEdge(int u, int v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
int a[305];
bool vis[305];
bool t(int st)
{
    queue<int> q;
    q.push(st);
    vis[st] = true;
    int cnt = 1;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        for (int i = head[x]; i; i = e[i].net)
        {
            if (a[e[i].v] < a[x] && !vis[e[i].v])
            {
                vis[e[i].v] = true;
                q.push(e[i].v);
                cnt++;
            }
        }
    }
    return cnt == n;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf(d2, &n, &m);
    for (int i = 1; i <= n; i++)
        scanf(d1, a + i);
    for (int i = 1; i <= m; i++)
    {
        scanf(d2, &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    bool flag = t(max_element(a + 1, a + n + 1) - a);
    if (flag == 1)
        printf("%d", max_element(a + 1, a + n + 1) - a);
    else
        printf("Non");
    return 0;
}