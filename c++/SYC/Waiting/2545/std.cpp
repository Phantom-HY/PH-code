#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[105], b[105];
bool check(int a[], int b[])
{
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
            return false;
    return true;
}
bool flag_1(int a[105], int b[105])
{
    bool flag = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; a[j] < a[j - 1] && j > 1; j--)
            swap(a[j], a[j - 1]);
        if (flag == 1)
            break;
        if (check(a, b))
            flag = 1;
    }
    if (flag == 1)
    {
        puts("Insertion Sort");
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        return true;
    }
    return false;
}
bool flag_2(int a[105], int b[105])
{
    bool flag = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; a[j] < a[j - 1] && j > 1; j--)
            swap(a[j], a[j - 1]);
        if (flag == 1)
            break;
        if (check(a, b))
            flag = 1;
    }
    if (flag == 1)
    {
        puts("Heap Sort");
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        return true;
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    flag_1(a, b);
    return 0;
}