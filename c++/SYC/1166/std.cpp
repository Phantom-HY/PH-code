#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
int m, n;
unordered_map<int, int> mp;
int a;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    while (scanf("%d%d", &m, &n) != -1)
    {
        mp.clear();
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a);
            if (mp[a] == 0 || cnt - mp[a] >= m)
                mp[a] = ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}