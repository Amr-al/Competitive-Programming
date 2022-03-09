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
//int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
const ll N = 1e6+5,MOD = 998244353, INF = 2e18;
ll n, m, t, len, a[N], seg[N];
void build(int v,int l,int r)
{
    if(l == r)
    {
        seg[v] = a[l];
        return;
    }
    int mid = (l+r) / 2;
    build(v*2,l,mid);
    build(v*2+1,mid+1,r);
    seg[v] = min(seg[v*2],seg[v*2+1]);
}
ll get(int v,int l,int r,int s,int e)
{
    if(l > e || r < s)
        return 1e9;
    if(l >= s && e >= r)
        return seg[v];
    int mid = (r+l) / 2;
    return min(get(v*2,l,mid,s,e),get(v*2+1,mid+1,r,s,e));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    len = 1;
    while(len < n)
        len *= 2;
    for(int i = 1; i <= n ;++i)
        cin >> a[i];
    build(1,1,len);
    cin >> t;
    while(t--)
    {
        ll l,r;
        cin >> l >> r;
        l++,r++;
        cout << get(1,1,len,l,r) << '\n';
    }
}
