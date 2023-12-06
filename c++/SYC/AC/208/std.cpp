#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int fa[105];
int Get(int x,int dep =0)
{
    if (fa[x]!=0)
        return Get(fa[x],dep+1);
    return dep;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        fa[a] = b;
    }
    int da,db;
    da = Get(1);
    db = Get(2);
    if (da==db)
        puts("You are my brother");
    else if(da>db)
        puts("You are my elder");
    else
        puts("You are my younger");
    return 0;
}