#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int v;
int g[85][85];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &v);
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char x[5];
            scanf("%s ",x);
            if (x[0] != '-'||(x[1]>='0'&&x[1]<='9'))
            {
                sscanf(x, "%d", &g[i][j]);
            }
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
    for (int i=1;i<=n;i++)
        if (i!=v)
            printf("(%d -> %d) = %d\n",v,i,g[v][i]);
    return 0;
}