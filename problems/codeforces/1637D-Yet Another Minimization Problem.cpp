#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 105,MOD = 1e8+7,INF = 2e18;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
ll m, t,dp[N][N*100];
class get_ans
{
    int n;
    int *a;
    int *b;
    ll ans;
public:
    get_ans(int x)
    {
        n = x;
        ans = 0;
        a = new int[x+2];
        b = new int[x+2];
        memset(dp,-1,sizeof dp);
        input();
        ans += 2*solve(1,0,0);
    }
    ~get_ans()
    {
        delete[] a;
        delete[] b;
    }
private:
    void input()
    {
        for(int i = 1; i <= n ; ++i)
            cin >> a[i],
                ans += (n-1) * (ll)pow(a[i],2);
        for(int i = 1; i <= n ; ++i)
        {
            cin >> b[i];
            ans += (n-1) * (ll)pow(b[i],2);
        }
    }
    ll solve(int idx,int sum,int sum2)
    {
        if(idx > n)
            return 0;
        ll &ret = dp[idx][sum];
        if(~ret)
            return ret;
        ret = INF;
        ret = a[idx]*sum + b[idx] * sum2 + solve(idx+1,sum + a[idx],sum2 + b[idx]);
        ret = min(ret,b[idx]*sum + a[idx] * sum2 + solve(idx+1,sum + b[idx],sum2 + a[idx]));
        return ret;
    }
public:
    ll getres()
    {
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> m;
        get_ans res(m);
        cout << res.getres() << '\n';
    }
    return 0;
}
