#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
char a[1000005];
int num[1000005];
// int se[2][1000005];
bitset<1000005> b;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d\n%s", &n, &m, &a);
    memset(num, -1, sizeof num);
    int cnt = 1;
    num[1] = num[0] = 1;
    for (int i = 1; i < strlen(a); i++)
    {
        if (a[i] != a[i-1])
            cnt^=1;
        num[i+1] = cnt;
    }
    while (m--)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
        {
            if (num[x] == num[y])
            {

            }
        }
        else
        {
            if (num[x] == num[y])
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}