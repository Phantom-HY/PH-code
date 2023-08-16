#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,e;
unordered_map<string,bool>m;
int bfs(string s,string e)
{
    m[s]=1;
    queue<pair<string,int>>q;
    q.push({s,0});
    int str=s.size();
    while(q.size())
    {
        auto x=q.front();
        q.pop();
        if (x.first==e)
            return x.second;
        for (int i=0;i<str;i++)
        {
            if (x.first[i]!='*')
            {
                if (i-1>=0&&x.first[i-1]=='*')
                {
                    swap(x.first[i],x.first[i-1]);
                    if(!m[x.first])m[x.first]=1,q.push({x.first,x.second+1});
                    swap(x.first[i],x.first[i-1]);
                }
                if (i+1<str&&x.first[i+1]=='*')
                {
                    swap(x.first[i],x.first[i+1]);
                    if(!m[x.first])m[x.first]=1,q.push({x.first,x.second+1});
                    swap(x.first[i],x.first[i+1]);
                }
                if (i-2>=0&&x.first[i-2]=='*')
                {
                    swap(x.first[i],x.first[i-2]);
                    if(!m[x.first])m[x.first]=1,q.push({x.first,x.second+1});
                    swap(x.first[i],x.first[i-2]);
                }
                if (i+2<str&&x.first[i+2]=='*')
                {
                    swap(x.first[i],x.first[i+2]);
                    if(!m[x.first])m[x.first]=1,q.push({x.first,x.second+1});
                    swap(x.first[i],x.first[i+2]);
                }
                if (i-3>=0&&x.first[i-3]=='*')
                {
                    swap(x.first[i],x.first[i-3]);
                    if(!m[x.first])m[x.first]=1,q.push({x.first,x.second+1});
                    swap(x.first[i],x.first[i-3]);
                }
                if (i+3<str&&x.first[i+3]=='*')
                {
                    swap(x.first[i],x.first[i+3]);
                    if(!m[x.first])m[x.first]=1,q.push({x.first,x.second+1});
                    swap(x.first[i],x.first[i+3]);
                }
            }
        }
    }
    return -1;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    cin>>s>>e;
    printf("%d",bfs(s,e));
    return 0;
}