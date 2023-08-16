#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define x first
#define y second
int n, ans;
PII a[2005];
int fun(PII a, PII b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].y);
    for (int i = 1; i <= n; i++)
    {
        unordered_map<int, int> m;
        for (int j = 1; j <= n; j++)
            m[fun(a[i], a[j])]++;
        for (auto &&j : m)
            ans += j.y * (j.y - 1);
    }
    printf("%d", ans);
    return 0;
}