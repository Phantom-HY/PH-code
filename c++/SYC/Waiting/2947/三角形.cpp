#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans;
int x[305], y[305];
bool s(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
bool check(int i, int j, int z)
{

    pair<int, int> l[4] = {{x[i], y[i]}, {x[j], y[j]}, {x[z], y[z]}};
    sort(l, l + 3, s);
    int p_1, p_2, p_3, p_4;
    p_1 = l[1].first - l[0].first;
    p_2 = l[2].first - l[1].first;
    p_3 = l[1].second - l[0].second;
    p_4 = l[2].second - l[1].second;
    if (p_1 == p_2 && p_3 == p_4)
        return 0;
    if (min(p_1,p_2)!=0&&max(p_1,p_2)%min(p_1,p_2)==0&&min(p_3,p_4)!=0&&max(p_3,p_4)%min(p_3,p_4)==0)
        if (max(p_1,p_2)/min(p_1,p_2)==max(p_3,p_4)/min(p_3,p_4))
        return 0;
    return 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", x + i, y + i);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int z = j + 1; z <= n; z++)
                if (check(i, j, z))
                    ans++;
    printf("%lld", ans);
    return 0;
}