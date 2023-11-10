#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define d1 "%d"
#define d2 "%d%d"
int n, s;
int a[1005], b[1005];
void fun(int x)
{
    if (s<=a[x])
    {
        printf(d1, x);
        exit(0);
    }
    s -= a[x];
    fun(b[x]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf(d2, &n, &s);
    for (int i = 1; i <= n; i++)
        scanf(d1, &a[i]);
    for (int i = 1; i <= n; i++)
        scanf(d1, &b[i]);
    fun(1);
    return 0;
}