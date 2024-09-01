#include<bits/stdc++.h>
using namespace std;
int t;
int f[30005];
int q[30005];
int s[30005];
void init()
{
	for (int i = 1;i<=30000;i++)
		f[i] = i,q[i] = 0,s[i] = 1;
}
int find(int x)
{
	if (f[x] == x)
		return x;
	int fx = find(f[x]);
	q[x]+=q[f[x]]; 
	return f[x] = fx;
}
void merge(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	q[fx]+=s[fy];
	f[fx] = fy;
	s[fy] += s[fx];
	s[fx] = 0;
}
void check(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
//	printf("%d %d\n",q[x],q[y]);
	if (fx != fy)
	{
		printf("-1\n");
		return ;
	}
	printf("%d\n",abs(q[x]-q[y])-1);
}
int main()
{
//	freopen("data.in","r",stdin);
	init();
	scanf("%d\n",&t);
	while(t--)
	{
		char op;
		int x,y;
		scanf("%c %d %d\n",&op,&x,&y);
//		printf("%c %d %d\n",op,x,y);
		if (op=='M')
			merge(x,y);
		else
			check(x,y);
	}
	return 0;
}