#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, p, h, m;
set<pair<int,int>>s;
int cnt[10005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d%d%d", &n, &p, &h, &m);
    for (int i = 1; i <= m; i++)
    {
        pair<int, int> z;
        scanf("%d%d", &z.first, &z.second);
        if (z.first>z.second)
            swap(z.first,z.second);
        s.insert(z);
    }
    while(!s.empty())
    {
        auto z=*s.begin();
        s.erase(z);
        cnt[z.first + 1]--;
        cnt[z.second]++;
    }
    for (int i = 1; i <= n; i++)
        cnt[i]+=cnt[i-1],printf("%d\n", cnt[i] + h);
    return 0;
}