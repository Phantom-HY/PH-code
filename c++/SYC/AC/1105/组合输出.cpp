#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
vector<int> ans;
void bdfs(int x, int l)
{
    if (x > n && l != m)
        return;
    if (l == m)
    {
        for (int i = 0; i < m; i++)
            printf("%d%c", ans[i], i == m - 1 ? '\n' : ' ');
        return;
    }
    for (int i = x; i <= n; i++)
        ans.push_back(i), bdfs(i + 1, l + 1), ans.pop_back();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin >> n >> m;
    bdfs(1, 0);
    return 0;
}