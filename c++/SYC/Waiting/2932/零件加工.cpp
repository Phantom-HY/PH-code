#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, q;
int a, l;
vector<int> e[100005];
bool vis[100005];
int bfs(int x, int l)
{
    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= q; i++)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &a, &l);
        int dep = bfs(a, l);
        printf("%d %d %d\n",a,l,dep);
        if (dep == -1)
            printf("No\n");
        else
        {
            puts((l-dep)%2==0?"Yes":"No");
        }
    }
    return 0;
}