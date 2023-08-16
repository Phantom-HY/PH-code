#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w, net;
} e[200005];
int n, m, head[100005], pos, u, v, w;
void addEdge(int u, int v, int w = 0)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
int d[100005];
void TopoSort()
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        printf("%d ", u);
        for (int i = head[u]; i; i = e[i].net)
        {
            int v = e[i].v;
            d[v]--;
            if (d[v] == 0)
                q.push(v);
        }
    }
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
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        d[v]++;
    }
    TopoSort();
    return 0;
}