#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
char s[1005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        int n = strlen(s);
        bool flag = 0;
        for (int i = 1; i < n; i++)
        {
            flag = s[i] != s[i - 1];
            if (flag)
                break;
        }
        if (!flag)
        {
            if (s[0] == 'C')
                puts("0");
            else
                printf("%lld\n", (1LL << n) - 1);
        }
    }
    return 0;
}