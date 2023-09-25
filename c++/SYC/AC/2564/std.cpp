#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n;
int a[2005];
void print(int x)
{
    if (x > n)
        return;
    print(2 * x);
    print(2 * x + 1);
    printf("%d ", a[x]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d%d", &m, &n);
    while (m--)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        bool flag[2] = {0, 0};
        for (int i = 1; i <= n; i++)
            if ((i * 2 <= n && a[i] < a[i * 2]) ||
                (i * 2 + 1 <= n && a[i] < a[i * 2 + 1]))
            {
                flag[0] = 1;
                break;
            }
        for (int i = 1; i <= n; i++)
            if ((i * 2 <= n && a[i] > a[i * 2]) ||
                (i * 2 + 1 <= n && a[i] > a[i * 2 + 1]))
            {
                flag[1] = 1;
                break;
            }
        puts(flag[0] && flag[1] ? "Not Heap" : (flag[1] ? "Max Heap" : "Min Heap"));
        print(1);
        puts("");
    }
    return 0;
}