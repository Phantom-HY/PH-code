#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dep[200005];
int col[200005];
int k;
struct Edge
{
    int u, v, net;
} e[100005];
int n, head[100005], pos, u, v;
void addEdge(int u, int v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", col + i, &v);
        addEdge(v, i);
    }

    return 0;
}