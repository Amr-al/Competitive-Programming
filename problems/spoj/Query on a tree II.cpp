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
ll n, m, t, par[N][20], dp[N], dis[N][20];
vector<pi> graph[N];
void dfs(int s,int p,int d)
{
    par[s][0] = p;
    dp[s] = dp[p] + 1;
    dis[s][0] = d;
    for(auto it:graph[s])
        if(it.ft != p)
            dfs(it.ft,s,it.sc);
}
void build()
{
    dfs(1,0,0);
    for(int i = 1; i < 20 ;++i){
        for(int j = 1; j <= n ;++j){
            par[j][i] = par[par[j][i-1]][i-1];
            dis[j][i] += dis[j][i-1] + dis[par[j][i-1]][i-1];
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
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n ;++i)
        {
            graph[i].clear();
            for(int j = 0 ; j < 20 ; ++j)
            {
                dis[i][j] = 0;
                par[i][j] = 0;
                dp[i] = 0;
            }
        }
        for(int i = 0 ; i < n-1 ; ++i)
        {
            int a,b,c;
            cin >> a >> b >> c;
            graph[a].pb({b,c});
            graph[b].pb({a,c});
        }
        build();
        while(1)
        {
            string s;
            int a,b,l,k;
            cin >> s;
            if(s == "DIST"){
                cin >> a >> b;
                l = lca(a,b);
                ll sum = 0 ;
                int k = dp[a] - dp[l];
                for(int i = 0; i < 20 ;++i){
                    if(k &(1<<i)){
                        sum += dis[a][i];
                        a = par[a][i];
                    }
                }
                k = dp[b] - dp[l];
                for(int i = 0; i < 20 ;++i){
                    if(k &(1<<i)){
                        sum += dis[b][i];
                        b = par[b][i];
                    }
                }
                cout << sum << '\n';
            }
            else if(s == "KTH")
            {
                cin >> a >> b >> k ;
                k--;
                l = lca(a,b);
                ll dis1 = dp[a] - dp[l],dis2 = dp[b] - dp[l];
                if(dis1 >= k)
                {
                    for(int i = 0; i < 20 ;++i){
                        if(k &(1<<i)){
                            a = par[a][i];
                        }
                    }
                    cout << a << '\n';
                }else{
                    k -= dis1;
                    k = dis2-k;
                    for(int i = 0; i < 20 ;++i){
                        if(k &(1<<i)){
                            b = par[b][i];
                        }
                    }
                    cout << b << '\n';
                }
            }else{
                break;
            }
        }
    }
    return 0;
}
