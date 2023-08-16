#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n, v[25];
bool dfs(int a,int b,int c,int x, int cnt)
{
    if (x==n+1)
    {
        if (a!=b||b!=c||a!=c)return 0;
        return 1;
    }
    return dfs(a+v[x],b,c,x+1,cnt)||dfs(a,b+v[x],c,x+1,cnt)||dfs(a,b,c+v[x],x+1,cnt);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", v + i), cnt += v[i];
        if (cnt%3!=0)
            printf("no\n");
        else 
        {
            printf("%s\n",dfs(0,0,0,1,cnt)?"yes":"no");
        }
    }
    return 0;
}