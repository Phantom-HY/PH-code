#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m;
string a;
bool b[105];
int ans[105];
void dfs(int num, int sum, int t)
{
    if (t > m)
        return;
    if (sum >= m && num != a.size())
        return;
    if (num == a.size())
    {
        ans[++sum] = t;
        if (sum != m)
            return;
        for (int i = 1; i <= m; i++)
            cout << ans[i] << " \n"[i == m];
        return;
    }
    if (num == 0)
        dfs(num + 1, sum, a[num] - '0');
    else
    {
        if (!b[t])
        {
            ans[sum + 1] = t;
            b[t] = 1;
            dfs(num + 1, sum + 1, a[num] - '0');
            b[t] = 0;
        }
        dfs(num + 1, sum, t * 10 + a[num] - '0');
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin >> a;
    for (int i = 0; i != a.size(); ++m)
    {
        if (m + 1 < 10)
            i += 1;
        else if (m+1<100)
            i += 2;
    }
    dfs(0, 0, 0);
    return 0;
}