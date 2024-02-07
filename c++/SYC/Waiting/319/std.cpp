#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
int a[300000];
int ans = 1e9;
bool check(int x)
{
    int i = 1;
    int cnt = -1e9;
    while (i + x <= n)
    {
        cnt = max(cnt, a[i + x-1] - a[i]);
        i += x;
    }
    if (i != n)
        cnt = max(cnt, a[n] - a[i]);
    return cnt >= ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int l = k, r = n;
    while (l <= r)
    {
        
    }
    return 0;
}