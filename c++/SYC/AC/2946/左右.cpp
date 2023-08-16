#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l[500005], r[500005], l_len = 1, r_len;
int n, x = 1;
char c;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%c", &c);
        if (c == 'R')
            l[++l_len] = x++;
        else
        {
            r[++r_len] = l[l_len];
            l[l_len] = x++;
        }
    }
    for (int i = 1; i <= l_len; i++)
        printf("%d ", l[i]);
    for (int i = r_len; i > 0; i--)
        printf("%d ", r[i]);
    return 0;
}