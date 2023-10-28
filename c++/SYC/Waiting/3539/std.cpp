#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l, n, m;
int w[1000005], d[1000005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("washing.in", "r", stdin);
    freopen("washing.out", "w", stdout);
#endif
    scanf("%d%d%d", &l, &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &d[i]);
    if (l == 1)
    {
        printf("%d", *min_element(w + 1, w + n + 1) + *min_element(d + 1, d + m + 1));
        exit(0);
    }
    
    return 0;
}