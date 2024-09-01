#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w, net;
} e[100005];
int n, m, head[100005], pos, u, v, w;
void addEdge(int u, int v, int w)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
int d[100005];
void TopoSort()
{
    // priority_queue<int, vector<int>, greater<int>> q;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        // int u = q.top();
        int u = q.front();
        q.pop();
        // printf("%d ", u);
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

    return 0;
}