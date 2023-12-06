#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a;
int ans = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &a);
        if (a % 2 == 1)
            ans ^= a;
    }
    printf("%d", ans);
    return 0;
}