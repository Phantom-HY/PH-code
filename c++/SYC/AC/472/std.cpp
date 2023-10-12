#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll u, v, p;
unordered_map<ll, ll> pre[2], op[2], vis[2], dis[2];
ll qpow(ll a, ll b, ll MOD)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD, b >>= 1;
    }
    return ans;
}
void print1(ll cur)
{
    if (cur == u)
        return;
    print1(pre[0][cur]);
    printf("%lld ", op[0][cur]);
}
void print2(ll cur)
{
    if (cur == v)
        return;
    printf("%lld ", op[1][cur]);
    print2(pre[1][cur]);
}
void fun(queue<ll> &q, int fd)
{
    if (q.empty())
        return;
    ll cur = q.front();
    q.pop();
    for (int i = 1; i <= 3; i++)
    {
        ll t;
        if (i == 1)
            t = (cur + 1) % p;
        else if (i == 2)
            t = (cur - 1 + p) % p;
        else
            t = qpow(cur, p - 2, p);
        if (vis[fd].count(t) == 0)
        {
            pre[fd][t] = cur;
            op[fd][t] = i;
            if (fd == 1 && i != 3)
                op[fd][t] = 3 - i;
            vis[fd][t] = 1;
            q.push(t);
            dis[fd][t] = dis[fd][cur] + 1;
            if (vis[!fd].count(t))
            {
                printf("%lld\n", dis[0][t] + dis[1][t]);
                print1(t), print2(t);
                exit(0);
            }
        }
    }
}
void bfs()
{
    queue<ll> qa, qb;
    qa.push(u);
    qb.push(v);
    vis[0][u] = vis[1][v] = 1;
    while (qa.size() || qb.size())
        fun(qa, 0), fun(qb, 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif
    scanf("%lld%lld%lld", &u, &v, &p);
    bfs();
    return 0;
}