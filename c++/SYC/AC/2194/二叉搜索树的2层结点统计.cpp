#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct Tree
{
    int data;
    int l=-1,r=-1;
    int dep=0;
}a[1005];
int mdep;
void add(int x,int data,int i)
{
    if (data<=a[x].data)
    {
        if (a[x].l==-1)
        {
            a[x].l=i;
            a[i].data=data;
            a[i].dep=a[x].dep+1;
        }
        else
            add(a[x].l,data,i);
    }
    else
    {
        if (a[x].r==-1)
        {
            a[x].r=i;
            a[i].data=data;
            a[i].dep=a[x].dep+1;
        }
        else
            add(a[x].r,data,i);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    a[0].data=x;
    a[0].dep=0;
    for(int i=1;i<n;i++){
        scanf("%d",&x);
        add(0,x,i);
        mdep=max(mdep,a[i].dep);
    }
    int ans=0;
    for (int i=0;i<n;i++)
    {
        if (a[i].dep==mdep||a[i].dep==mdep-1)
            ans++;
    }
    printf("%d",ans);
    return 0;
}