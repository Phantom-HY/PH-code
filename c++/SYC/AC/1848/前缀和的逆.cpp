#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[105];
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
        printf("%d ", a[i] - a[i - 1]);
    return 0;
}