#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int a[12000005], len;
int s(int l, int r, int c)
{
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (a[mid] == c)
            return mid;
        if (a[mid] < c)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    len = n;
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        if (a[i - 1] > a[i])
            flag = 1;
        if (flag == 0)
        {
            len++;
            a[len] = a[i];
        }
    }
    // for (int i = 1; i <= len; i++)
    //     printf("%d ", a[i]);
    // puts("");
    while (m--)
    {
        int i;
        scanf("%d", &i);
        int x = s(len - n + 1, len, i);
        if (x <= n)
            printf("%d\n", x);
        else
            printf("%d\n", x);
    }
    return 0;
}