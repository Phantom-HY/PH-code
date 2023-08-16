#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
char x[10005];
int f(int c)
{
    int ans = 0;
    for (int i = 0; i < c; i++)
        ans *= 10, ans += (x[i] - '0');
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", x);
        sort(x, x + strlen(x));
        bool flag=1;
        do
        {
            if (x[0] == '0')
                continue;
            int k = f(strlen(x));
            if ((k & (k - 1)) == 0)
            {
                puts("Yes");
                flag=0;
                break;
            }
        } while (next_permutation(x, x + strlen(x)));
        if (flag)
            puts("No");
    }
    return 0;
}