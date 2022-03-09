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
const ll N = 2e6+5,MOD = 1e9+9,INF = 2e12;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll m, n, t, h[N],power[N],p=31;
string s,s2;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    power[0]= 1;
    for(int i = 1 ; i < N ;++i)
        power[i] = power[i-1] * p % MOD;
    while(cin >> n){
        cin >> s >> s2;
        ll s_hash = 0;
        for(int i = 0; i < sz(s2) ;++i)
        {
            h[i+1] = (h[i] + (s2[i]-'a'+1) * power[i]) % MOD;
        }
        for(int i = 0 ; i < sz(s) ;++i)
        {
            s_hash = (s_hash + (s[i] - 'a' + 1)*power[i])%MOD;
        }
        int ok = 0;
        for(int i = 0 ; i + sz(s) - 1 < sz(s2) ;++i)
        {
            if(s_hash * power[i] % MOD == (h[i+sz(s)]+MOD-h[i]) % MOD)
                cout << i << endl,ok++;
        }
        if(!ok)
            cout << endl;
    }
    return 0;
}
