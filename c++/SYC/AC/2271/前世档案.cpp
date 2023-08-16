#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d\n", &n, &m);
    int cnt = 1 << n;
    while (m--)
    {
        int l = 0, r = 1 << n;
        char c;
        for (int i = 1; i <= n; i++)
        {
            scanf("%c", &c);
            if (c=='y')
            {
                r=l+r>>1;
            }
            else
                l=l+r>>1;
            // printf("%d %d\n",l,r);
        }
        scanf("\n");
        printf("%d\n",r);
    }
    return 0;
}