#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long
#define pi pair<ll,ll>
#define vi vector<ll>
#define sc second
#define ft first
#define all(s) s.begin(),s.end()
#define rall(s) s.rbegin(),s.rend()
#define sz(s) s.size()
const ll N = 2e6+5,MOD = 1e9+7,INF = LONG_MAX;
using namespace std;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll n, m, t, SZ[N], par[N];
vector<pi> closed,build;
set<int> tmp;
void make_set()
{
    for(int i = 0; i <= n ;++i)
    {
        par[i] = i;
        SZ[i] = 1;
    }
}
ll find_set(int s)
{
    if(s == par[s])
        return s;
    return par[s] = find_set(par[s]);
}
void union_set(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
        if(SZ[a] < SZ[b])
            swap(a,b);
        par[b] = a;
        SZ[a] += SZ[b];
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    make_set();
    for(int i = 1 ; i < n ;++i)
    {
        int u,v;
        cin >> u >> v;
        int a = find_set(u) , b = find_set(v);
        if(a != b)
            union_set(a,b);
        else
            closed.pb({u,v});
    }
    for(int i = 1; i <= n ;++i)
    {
        find_set(i);
        tmp.insert(par[i]);
    }
    if(sz(tmp) == 1)
        return cout << 0,0;
    ll rf = *tmp.begin();
    tmp.erase(tmp.begin());
    for(auto it:tmp)
        build.pb({rf,it});
    cout << sz(build) << '\n';
    for(int i = 0; i < sz(build) ;++i)
    {
        cout << closed[i].ft << ' ' << closed[i].sc << ' ' << build[i].ft << ' ' << build[i].sc << endl;
    }

}
