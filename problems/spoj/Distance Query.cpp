#include <bits/stdc++.h>
#include <sys/types.h>
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<ll>
#define sc second
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
const ll N = 3e5+10,MOD = 1e9+7,INF = 2e12;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll n, m, t, par[N][20], dp[N], mn[N][20], mx[N][20];
vector<pi> graph[N];
void dfs(int s,int p,ll mnn,ll mmx)
{
    par[s][0] = p;
    dp[s] = dp[p] + 1;
    mn[s][0] = mnn;
    mx[s][0] = mmx;
    for(auto it:graph[s])
        if(it.ft != p)
            dfs(it.ft,s,it.sc,it.sc);
}
void build()
{
    dfs(1,0,INF,0);
    for(int i = 1; i < 20 ;++i){
        for(int j = 1; j <= n ;++j){
            par[j][i] = par[par[j][i-1]][i-1];
            mn[j][i] = min(mn[j][i-1],mn[par[j][i-1]][i-1]);
            mx[j][i] = max(mx[j][i-1],mx[par[j][i-1]][i-1]);
        }
    }
}
int lca(int a,int b)
{
    if(dp[a] < dp[b])
        swap(a,b);
    int k = dp[a] - dp[b];
    for(int i = 0; i < 20 ;++i)
        if(k &(1<<i))
            a = par[a][i];
    if(a == b)
        return a;
    for(int j = 19; ~j ;--j)
    {
        if(par[a][j] != par[b][j])
        {
            a = par[a][j];
            b = par[b][j];
        }
    }
    return par[a][0];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n - 1; ++i)
    {
        int u,v,c;
        cin >> u >> v >> c;
        graph[v].pb({u,c});
        graph[u].pb({v,c});
    }
    build();
    cin >> t;
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        ll l = lca(a,b),tmpmx = 0,tmpmn = INF;
        int k = dp[a] - dp[l];
        for(int i = 0; i < 20 ;++i){
            if(k &(1<<i)){
                tmpmx = max(tmpmx,mx[a][i]);
                tmpmn = min(tmpmn,mn[a][i]);
                a = par[a][i];
            }
        }
        k = dp[b] - dp[l];
        for(int i = 0; i < 20 ;++i){
            if(k &(1<<i)){
                tmpmx = max(tmpmx,mx[b][i]);
                tmpmn = min(tmpmn,mn[b][i]);
                b = par[b][i];
            }
        }
        cout << tmpmn << ' ' << tmpmx << '\n';
    }
    return 0;
}
