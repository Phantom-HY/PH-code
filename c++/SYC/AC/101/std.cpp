#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[1005];
int k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    scanf("%d", &k);
    if (1 << (k - 1) > n)
        printf("EMPTY"), exit(0);
    for (int i = 1 << (k - 1); i <= n && i <= (1 << k) - 1; i++)
        printf("%d ", a[i]);
    return 0;
}