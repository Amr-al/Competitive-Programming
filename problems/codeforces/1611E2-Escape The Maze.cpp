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
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const ll N = 2e5+5,MOD = 1e9+7, INF = 2e18;
ll n, m, t, x, dp[N], ans;
vi graph[N];
void dfs(int s,int p)
{
    for(auto child:graph[s]){
        if(child != p){
            dfs(child,s);
            dp[s] = min(dp[s],dp[child]+1);
        }
    }
}
bool check(int s,int p,int cnt)
{
    if(cnt >= dp[s]){
        ans++;
        return false;
    }
    if(cnt < dp[s] && sz(graph[s]) == 1 && s != 1){
        return true;
    }
    int ok = 0;
    for(auto child:graph[s])
    {
        if(child != p){
            ok |= check(child,s,cnt+1);
        }
    }
    return ok;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m ;
        ans = 0;
        for(int i = 0; i <= n ;++i){
            graph[i].clear();
            dp[i] = INF;
        }
        for(int i = 1; i <= m ;++i){
            cin >> x;
            dp[x] = 0;
        }
        for(int i = 1; i < n ;++i){
            int u,v;
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        dfs(1,1);
        cout << (check(1,1,0)?-1:ans) << '\n';
    }
}
