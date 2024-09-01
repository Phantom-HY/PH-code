#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[2000005];
bool check(int l, int r)
{
    for (int i = l, j = r; i <= j; i++, j--)
        if (s[i] != s[j])
            return false;
    return true;
}
vector<pair<int, int>> m;
int ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            if (check(i, j))
                m.push_back({i, j});
    sort(m.begin(), m.end());
    for (int i = 0; i < m.size(); i++)
        for (int j = i + 1; j < m.size(); j++)
            if (m[j].first <= m[i].second)
                ans++, ans %= 51123987;
    printf("%d\n", ans);
    return 0;
}