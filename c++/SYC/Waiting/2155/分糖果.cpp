#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u, v, net;
} e[2000005];
int n, m, head[100005], pos, u, v;
void addEdge(int u, int v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
int c, k;
bool vis[100005];
void sweet(int x, int time=0)
{
    queue<int>q;
    q.push(x);
    while(!q.empty())
    {
        int len=q.size();
        time++;
        for(int i=0;i<len;i++)
        {
            int u=q.front();
            q.pop();
            for (int i=head[u];i;i=e[i].net)
            {
                int v=e[i].v;
                if(!vis[v])
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    printf("%d",time+k);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d%d", &n, &m, &c, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    sweet(c);
    return 0;
}
