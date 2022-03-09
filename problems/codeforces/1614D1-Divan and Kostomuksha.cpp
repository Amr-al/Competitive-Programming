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
const int N = 5e6+5,MOD = 1e9+7;//INF = 2e18;
int n, m, t, frq[N], a[N];
ll dp[N],ans,mx;
vector<int> dv[N];
bool tmm[N];
void get(ll mx)
{
    for(int i = 1; i <= mx ;++i)
    {
        for(int j = i; j <= mx ;j+=i){
            if(tmm[j]){
                dv[j].push_back(i);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n ;++i)
    {
        cin >> a[i];
        tmm[a[i]] = true;
        mx = max(mx,(ll)a[i]);
    }
    get(mx);
    for(int i = 1; i <= n ;++i)
    {
        for(auto it:dv[a[i]])
            frq[it]++;
    }
    for(ll i = mx; i ;--i)
    {
        for(ll j = i*2LL; j <= mx ;j+=i){
            dp[i] = max(dp[i],dp[j] + (frq[i] - frq[j])*i);
        }
        dp[i] = max(dp[i],frq[i] * i);
        ans = max(ans,dp[i]);
    }
    cout << dp[1];
}
