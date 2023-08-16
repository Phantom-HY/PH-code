#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, t;
int a[100005];
unordered_map<ll, bool> b;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        b[a[i] - a[i - 1]] = 1;
    }
    while (t--)
    {
        bool flag=0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", a + i);
            if (!flag&&!b[a[i]-a[i-1]])
                flag=1;
        }
        puts(flag==1?"No":"Yes");
    }
    return 0;
}