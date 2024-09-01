#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
int n;
char s[2000005], a[2000005], b[2000005];
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &n);
        scanf("%s", s + 1);
        for (int i = 0; i <= n; i++)
        {
            a[i] = s[i];
            for (int j = i + 1; j <= n; j++)
                a[j] = s[j + n];
            for (int j = i + n; j >= i + 1; j--)
                b[j] = s[j];
            if (strcmp(a + 1, b + 1) == 0)
            {
                printf("%s\n%d\n", a + 1, i);
                break;
            }
        }
    }
    return 0;
}