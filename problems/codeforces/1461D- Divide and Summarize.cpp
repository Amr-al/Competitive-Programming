#include <bits/stdc++.h>
#define ll long long
#define all(s) s.begin(),s.end()
#define pb push_back
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
const ll N = 1e5+100,MOD = 1e9+7,INF = 2e18;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, t, a[N], ans, q;
struct st{
    ll mn,mx,sum;
}seg[N*4];
map<ll,int> m3aya;
void build(int v,int l,int r)
{
    if(l == r)
    {
        seg[v] = {a[l],a[l],a[l]};
        return;
    }
    int mid = (l+r) / 2;
    build(v*2,l,mid);
    build(v*2+1,mid+1,r);
    seg[v] = {min(seg[v*2].mn,seg[v*2+1].mn),
              max(seg[v*2].mx,seg[v*2+1].mx),
              seg[v*2].sum+seg[v*2+1].sum};
}
st get(int v,int l,int r,int s,int e)
{
    if(l > e || s > r)
        return {(ll)1e9,0,0};
    if(s <= l && r <= e)
        return seg[v];
    int mid = (l+r) / 2;
    st lf = get(v*2,l,mid,s,e), rt = get(v*2+1,mid+1,r,s,e);
    return{min(lf.mn,rt.mn),
           max(lf.mx,rt.mx),
           lf.sum+rt.sum};
}
int first_above(int v,int l,int r,int val)
{
    int mid = (l+r) / 2;
    if(l == r){
        if(a[l] > val)
            return l-1;
        return l;
    }
    if(seg[v*2].mx > val)
        return first_above(v*2,l,mid,val);
    else
        return first_above(v*2+1,mid+1,r,val);
}
void solve(int l,int r)
{
    if(l >= r){
        if(l == r)
            m3aya[a[l]]++;
        return;
    }
    st tmp = get(1,1,n,l,r);
    int mid = (tmp.mn + tmp.mx) / 2;
    int f = first_above(1,1,n,mid);
    m3aya[tmp.sum] = 1;
    if(r != f)
     solve(l,f);
    solve(f+1,r);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        m3aya.clear();
        cin >> n >> m;
        for(int i = 1; i <= n ;++i)
            cin >> a[i];
        sort(a+1,a+n+1);
        build(1,1,n);
        solve(1,n);
        while(m--){
            cin >> q ;
            cout << (m3aya[q]?"Yes":"No") << '\n';
        }
    }
    return 0;
}
