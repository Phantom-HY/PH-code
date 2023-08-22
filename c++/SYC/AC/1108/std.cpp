#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[200005], cnt[200005], len;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        if (x == 0)
        {
            scanf("%d", &x);
            a[++len] = x;
            cnt[len] = max(cnt[len - 1], a[len]);
        }
        else if (x == 1)
            len--;
        else
        {
            printf("%d\n", cnt[len]);
        }
    }
    return 0;
}