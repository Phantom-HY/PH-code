#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[205], b[205];
int fun(int x)
{
    if (x>n)return 0;
    return min(fun(x+a[x]),fun(x+b[x]))+1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i);
    printf("%d",fun(1));
    return 0;
}