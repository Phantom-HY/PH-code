#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l, t, o;
int a[100005];
bool vis[35];
int main()
{
    cin >> l >> t >> o;
    for (int i = 1; i <= l; i++)
        a[i] = 1;
    while (o--)
    {
        int l, r, x;
        char op;
        cin >> op;
        if (op == 'C')
        {
            cin >> l >> r >> x;
            for (int i = l; i <= r; i++)
                a[i] = x;  
        }
        else
        {
            memset(vis, 0, sizeof vis);
            cin >> l >> r;
            int ans = 0;
            for (int i = l; i <= r; i++)
            {
                if (!vis[a[i]])
                    ans++;
                vis[a[i]] = 1;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}