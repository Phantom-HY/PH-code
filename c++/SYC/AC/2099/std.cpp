#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        printf("%d ", __builtin_popcount(i));
    return 0;
}