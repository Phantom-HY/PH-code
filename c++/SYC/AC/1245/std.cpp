#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<int> a[100005];
int idx[100005];
int ans[500005], len;
void dfs(int x)
{
    for (int i = idx[x]; i < a[x].size(); i = idx[x])
    {
        idx[x] = i + 1;
        dfs(a[x][i]);
    }
    ans[++len] = x;
}
int sum_1, sum_2, sum_3;
int x[100005], y[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        x[u]++;
        y[v]++;
    }
    int st = 1;
    for (int i = 1; i <= n; i++)
    {
        sum_1 += x[i] - y[i] == 1;
        if (x[i]-y[i]==1)
            st = i;
        sum_2 += x[i] - y[i] == -1;
        if (abs(x[i] - y[i])>1)
            sum_1 = 4;
    }
    if (sum_1 > 1 || sum_2 > 1)
    {
        printf("No");
        exit(0);
    }
    for (int i = 1; i <= n; i++)
        sort(a[i].begin(), a[i].end());
    dfs(st);
    if (len == m + 1)
    {
        for (int i = len; i >= 1; i--)
            printf("%d ", ans[i]);
        exit(0);
    }
    printf("No");
    return 0;
}