#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int f[100005];
int cnt[100005];
int find(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        f[fx] = fy,cnt[fy]+=cnt[fx];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++)
        f[i] = i,cnt[i]=1;
    for (int i = 0; i < m; i++)
    {
        char c;
        int x, y;
        scanf("%c ", &c);
        if (c == 'M')
            scanf("%d %d\n",&x,&y),merge(x, y);
        else
        {
            scanf("%d\n",&x);
            printf("%d\n",cnt[find(x)]);
        }
    }
    return 0;
}