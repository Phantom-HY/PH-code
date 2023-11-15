#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    srand(time(NULL));
    int n = 100, q = 1000;
    printf("%d %d\n", n, q);
    for (int i = 1; i <= n; i++)
        printf("%lld ", ll(rand() % 10000) * ll(rand() % 10000));
    printf("\n");
    while(q--)
    {
        int op=rand()%3+1;
        printf("%d ", op);
        if (op==1)
        {
            int l,r;
            l=rand()%n+1;
            r=rand()%n+1;
            if (l>r)
                swap(l,r);
            printf("%d %d %lld\n", l, r,ll(rand() % 10000) * ll(rand() % 10000));
        }else
        {
            int l,r;
            l=rand()%n+1;
            r=rand()%n+1;
            if (l>r)
                swap(l,r);
            printf("%d %d\n", l, r);
        }
    }
    return 0;
}