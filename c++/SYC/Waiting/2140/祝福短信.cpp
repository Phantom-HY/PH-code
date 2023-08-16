#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
string nm;
map<string,bool>z;
string S(string a)
{
	for (int i=0;i<a.size();i++)
		if (a[i]>='A'&&a[i]<='Z')a[i]=a[i]-'A'+'a';
	return a;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>nm;
		z[S(nm)]=1;
	}
	for (int i=1;i<=m;i++)
	{
		string l;
		cin>>l;
		l=S(l);
		if (z[l])
			z[l]=0,n--;
	}
	cout<<n;
	return 0;
}