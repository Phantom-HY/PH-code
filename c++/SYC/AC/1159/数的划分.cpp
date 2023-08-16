#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int dfs(int x,int step,int num)
{
    if (x==k)
    {
        if (num<=step)return 1;
        return 0;
    }
    int cnt=0;
    for (int i=num;i<=step/2;i++)
    {
        cnt+=dfs(x+1,step-i,i);
    }
    return cnt;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d%d",&n,&k);
    printf("%d",dfs(1,n,1));
    return 0;
}