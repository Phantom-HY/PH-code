#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct DDL
{
    int t,ddl;
}a[1005];
bool cmp(DDL a,DDL b)
{
    return a.ddl>b.ddl;
}
int ddl=INT_MAX,n;
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].t,&a[i].ddl);
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;i++)
        ddl=min(ddl,a[i].ddl)-a[i].t;
    printf("%d",max(ddl,-1));
    return 0;
}