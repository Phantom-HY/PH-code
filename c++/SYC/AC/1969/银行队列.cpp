#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<int> A, B;
int n, x;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            if (x%2)
                A.push(x);
            else
                B.push(x);
        }
        while(!A.empty()||!B.empty())
        {
            int cnt=2;
            while(cnt--&&!A.empty())
                printf("%d ",A.front()),A.pop();
            if (!B.empty())
                printf("%d ",B.front()),B.pop();
        }
        puts("");
    }
    return 0;
}