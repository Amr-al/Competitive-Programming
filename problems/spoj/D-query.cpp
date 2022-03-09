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
ll n, m, t, len, ans[N], freq[N], cnt, a[N];
struct query{
    int l,r,idx;
    bool operator <(query a)const{
        return make_pair(l/len,r) < make_pair(a.l / len , a.r);
    }
};
vector<query> q;
void add(int i)
{
    freq[a[i]]++;
    if(freq[a[i]] == 1)
        cnt++;
}
void remov(int i)
{
    freq[a[i]]--;
    if(freq[a[i]] == 0)
        cnt--;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    len = sqrt(n) ;
    for(int i = 1; i <= n ;++i)
        cin >> a[i];
    cin >> t;
    int curl = 1,curr = 0;
    for(int i = 0; i < t ;++i)
    {
        int l,r;
        cin >> l >> r;
        q.pb({l,r,i});
    }
    sort(all(q));
    for(auto it:q)
    {
        while(curl > it.l)
            add(--curl);
        while(curr < it.r)
            add(++curr);
        while(curl < it.l)
            remov(curl++);
        while(curr > it.r)
            remov(curr--);
        //cout << it.idx << endl;
        ans[it.idx] = cnt;
    }
    for(int i = 0; i < t ;++i)
        cout << ans[i] << '\n';
}
