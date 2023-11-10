#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int x[10005][10005];
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int y, int d)
{
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j))
            x[i][j] += d;
}
int get(int x,int y)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            ans += x[i][j];
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif

    return 0;
}