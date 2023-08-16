#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int n, k, a[7000005];
void quickSort(int l, int r, int k)
{
    if (l == r)
        return ;
    int i = l, j = r, x = a[l + r >> 1];
    while (i <= j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
            swap(a[i++], a[j--]);
    }
    if (j - l + 1 >= k)
        return quickSort(l, j, k);
    return quickSort(i, r, k - (j - l + 1));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    quickSort(1, n, k);
    printf("%d",a[k]);
    return 0;
}