#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5,MOD = 1e8+7,INF = 1e18;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll n, m, dp[N],t ,a[N];
ll solve(int i)
{
    if(i >= n)
        return 0;
    ll &ret = dp[i];
    if(~ret)
        return ret;
    ret = max(a[i] + solve(i+2),solve(i+1));
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    for(int i = 1; i <= t ;++i)
    {
        cin >> n ;
        for(int j = 0 ; j < n ;++j)
        {
            cin >> a[j];
            dp[j] = -1;
        }
        cout << "Case " << i << ": ";
        cout << solve(0) << '\n';
    }
    return 0;
}
