#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, len[2005], a[2005][1005], r[10000005];
bool sz[2005];
char cz[25];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while (scanf("%d", &n), n)
    {
        queue<int> xz, zc[2005];
        memset(sz, 0, sizeof sz);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &len[i]);
            for (int j = 1; j <= len[i]; j++)
                scanf("%d", &a[i][j]), r[a[i][j]] = i;
        }
        printf("Scenario #%d\n", ++k);
        while (scanf("%s", cz), cz[0] != 'S')
        {
            if (cz[0] == 'E')
            {
                int x;
                scanf("%d", &x);
                zc[r[x]].push(x);
                if (!sz[r[x]])
                {
                    xz.push(r[x]);
                    sz[r[x]] = 1;
                }
            }
            else
            {
                printf("%d\n", zc[xz.front()].front());
                zc[xz.front()].pop();
                if (zc[xz.front()].empty())
                {
                    sz[xz.front()] = 0;
                    xz.pop();
                }
            }
        }
        puts("");
    }
    return 0;
}