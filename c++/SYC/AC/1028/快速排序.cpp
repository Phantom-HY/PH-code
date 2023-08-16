#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005], n;
void quickSort(int l, int r)
{
    if (l >= r)
        return;
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
    quickSort(l, j),quickSort(i, r);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    quickSort(1, n);
    for (int i = 1; i <= n; i++)
        printf("%d\n", a[i]);
    return 0;
}