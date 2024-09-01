#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[15], b[15];
bool check(int x)
{
    for (int i = 1;i<x;i++)
        for (int j =i+1;j<=x;j++)   
            if (b[i]%x==b[j]%x)
                return 0;
    return 1;
}
void fun(int x)
{
    for (int i = 1; i <= x; i++)
        a[i] = i;
    do
    {
        int j = 1;
        for (int i = 1; i <= x; i++)
            j *= a[i], b[i] = a[i];
        if (check(x))
        {
            for (int i = 1;i<=x;i++)
                printf("%d ",a[i]);
            puts("");
            return;
        }
    } while (next_permutation(a + 1, a + 1 + x));
    puts("");
}
int t,n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        fun(n);
    }
    return 0;
}