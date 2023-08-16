#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string f(int n,int k)
{
    if (k==n)
        return "sin("+to_string(k)+")";
    return "sin("+to_string(k)+"+"+f(n,k+1)+")";
}
string g(int k)
{
    if (k==n)
        return "("+f(n-k+1,1)+"+"+to_string(k)+")";
    if (k!=1)
        return "("+g(k+1)+f(n-k+1,1)+"+"+to_string(k)+")";
    else 
        return g(k+1)+f(n-k+1,1)+"+"+to_string(k);
}
int main(){
    scanf("%d",&n);
    cout<<g(1);
    return 0;
}