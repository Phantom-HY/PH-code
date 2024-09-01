#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int val[200005];
struct Edge
{
    int u, v, net;
} e[100005];
int n, m, head[100005], pos, u, v;
void addEdge(int u, int v)
{
    e[++pos] = {u, v, head[u]};
    head[u] = pos;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    
    return 0;
}