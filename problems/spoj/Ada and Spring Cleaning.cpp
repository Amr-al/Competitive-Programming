#include <bits/stdc++.h>
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
const ll N = 3e5+10,MOD = 1e9+7,MOD2 = 1e9+9,INF = 2e12;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll n, m, t, pw[N],h[N],pw2[N],h2[N];
string s;
void get()
{
    ll p = 31;
    pw[0] = 1;
    for(int i = 1; i < N ;++i)
        pw[i] = (pw[i-1] * p)%MOD;
    p = 53;
    pw2[0] = 1;
    for(int i = 1; i < N ;++i)
        pw2[i] = (pw2[i-1] * p)%MOD2;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    get();
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s;
        for(int i = 0; i < n ;++i){
            h[i+1] = (h[i] + (s[i]-'a'+1)*pw[i])%MOD;
            h2[i+1] = (h2[i] + (s[i]-'a'+1)*pw2[i])%MOD2;
        }
        set<pi> ans;
        for(int i = 0; i <= n-m ;++i)
        {
            ll cur_h = (h[i+m]+MOD-h[i])%MOD;
            cur_h = (cur_h*pw[n-i-1])%MOD;
            ll cur_h2 = (h2[i+m]+MOD2-h2[i])%MOD2;
            cur_h2 = (cur_h2*pw2[n-i-1])%MOD2;
            ans.insert({cur_h,cur_h2});
        }
        cout << sz(ans) << '\n';
    }
    return 0;
}
