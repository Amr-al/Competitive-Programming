#include <bits/stdc++.h>
#include <sys/types.h>
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define vi vector<int>
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
//typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
const int N = 1e5+10,MOD = 998244353, INF = 1e18;
int n, mx, t, a[N], freq[N], freq2[N],len, anss[N];
struct query{
    int l,r,idx,res;
    bool operator<(query other) const{
        return make_pair(l / len, r) <
               make_pair(other.l / len, other.r);
    }
}ans[N];
void add(int i){
    freq2[freq[a[i]]]--;
    freq[a[i]]++;
    freq2[freq[a[i]]]++;
    mx = max(mx,freq[a[i]]);
}
void remove(int i){
    if(freq[a[i]] == mx && freq2[freq[a[i]]] == 1)
        mx--;
    freq2[freq[a[i]]]--;
    freq[a[i]]--;
    freq2[freq[a[i]]]++;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> t;
    len = sqrt(n);
    for(int i = 0; i < n ;++i)
        cin >> a[i];
    for(int i = 0; i < t ;++i){
        cin >> ans[i].l >> ans[i].r;
        ans[i].idx = i;
    }
    sort(ans,ans+t);
    int curl = 0,curr = -1;
    for(int i = 0; i < t ;++i){
        while(curl > ans[i].l)
            add(--curl);
        while(curr < ans[i].r)
            add(++curr);
        while(curl < ans[i].l)
            remove(curl++);
        while(curr > ans[i].r)
            remove(curr--);
        anss[ans[i].idx] = mx;
    }
    for(int i = 0; i < t;++i)
        cout << anss[i] << '\n';
}
