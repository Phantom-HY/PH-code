#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int x, y;
vector<int> a[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
    }
    for (int i = 1; i <= 100000; i++)
        for (auto &&j : a[i])
            printf("%d\n", j);
    return 0;
}