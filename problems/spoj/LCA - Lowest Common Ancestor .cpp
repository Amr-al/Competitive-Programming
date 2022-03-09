#include <bits/stdc++.h>
#include <sys/types.h>
#define ll long long
#define pb push_back
#define pi pair<int,int>
#define vi vector<ll>
#define sc second
#define endl '\n'
#define ft first
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define sz(s) s.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<pi, null_type, less<pi>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll N = 1e5+10,MOD = 1e9+7,INF = 2e12;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll n, m, t = 1, in[N], out[N], timer, p[N][22];
vi graph[N];
void dfs(int s,int pp)
{
    in[s] = timer++;
    p[s][0] = pp;
    for(int i = 1; i < 20 ;++i)
        p[s][i] = p[p[s][i-1]][i-1];
    for(auto it:graph[s])
    {
        if(it != pp)
            dfs(it,s);
    }
    out[s] = timer++;
}
bool is_ok(int a,int b)
{
    return (in[a] <= in[b] && out[a] >= out[b]);
}
int get(int a,int b)
{
    if(is_ok(a,b))
        return a;
    if(is_ok(a,b))
        return b;
    for(int i = 20; ~i ;--i)
    {
        if(p[a][i] && !is_ok(p[a][i],b))
            a = p[a][i];
    }
    return p[a][0];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
     cin >> t;
    for(int tst = 1; tst <= t ;++tst)
    {
        cin >> n;
        for(int i = 1; i <= n ;++i){
            graph[i].clear();
            for(int j = 0 ; j < 20 ;++j)
                p[i][j] = 0;
        }
        timer = 0;
        vi root(n+1,0);
        for(int i = 1; i <= n ;++i)
        {
            cin >> m;
            for(int j = 0,x; j < m ;++j)
            {
                cin >> x;
                graph[i].pb(x);
                graph[x].pb(i);
                root[x]++;
            }
        }
        for(int i = 1; i <= n ;++i)
        {
            if(!root[i])
            {
                m = i;
                break;
            }
        }
        dfs(m,0);
        cin >> m;
        cout << "Case " << tst << ":\n";
        while(m--)
        {
            int a,b;
            cin >> a >> b;
            cout << get(a,b) << '\n';
        }
    }
    return 0;
}
