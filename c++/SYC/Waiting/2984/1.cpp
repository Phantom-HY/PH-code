#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define t first
#define u second
int T, n, m, ans, v[155], o[155];
pair<int, int> w[155];
void dfs(int x, pair<int, int> step)
{
    if (step.u + v[x] <= ans)
        return;
    if (step.t + o[x] <= m)
    {
        ans=max(ans,step.u+v[x]);
        return ;
    }
    if (step.t > m)
        return;
    if (x == n + 1)
    {
        ans = max(ans, step.u);
        return;
    }
    dfs(x + 1, {step.t + w[x].t, step.u + w[x].u});
    dfs(x + 1, step);
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("data.in", "r", stdin);
    //     freopen("data.out", "w", stdout);
    // #endif
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &w[i].t, &w[i].u);
        sort(w + 1, w + 1 + n, greater<pair<int, int>>());
        v[n+1]=o[n+1]=0;
        for (int i = n; i > 0; i--)
            v[i] = v[i + 1] + w[i].u;
        for (int i = n; i > 0; i--)
            o[i] = o[i + 1] + w[i].t;
        dfs(1, {0, 0});
        printf("%d\n", ans);
    }
    return 0;
}