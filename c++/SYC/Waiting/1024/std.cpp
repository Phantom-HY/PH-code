#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, w, net;
} e[200005];
int n, head[100005], pos, u, v;
void addEdge(int u, int v, int w = 0)
{
    e[++pos] = {u, v, w, head[u]};
    head[u] = pos;
}
bool pd = 1;
int vispd[100005];
int apd[100005];
void fpd(int x, int co)
{
    apd[x] = co;
    for (int i = head[x]; i; i = e[i].net)
    {
        int v = e[i].v;
        fpd(v, co == 1 ? 2 : 1);
    }
}
int cnd;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        vispd[v]++;
        vispd[u]++;
        if (vispd[cnd]<vispd[v])
            cnd=v;
        if (vispd[cnd]<vispd[u])
            cnd=u;
        addEdge(u, v);
        if (vispd[v] > 2 || vispd[u] > 2)
            pd = 0;
    }
    if (pd)
    {
        printf("2\n");
        for (int i = 1; i <= n; i++)
            if (vispd[i] == 1)
                fpd(i, 1);
        for (int i = 1; i < n; i++)
            printf("%d\n", apd[e[i].u]);
        exit(0);
    }
    printf("%d\n",vispd[cnd]);
    
    return 0;
}