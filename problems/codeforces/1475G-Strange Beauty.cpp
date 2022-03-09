#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long
#define pi pair<int,int>
#define vi vector<ll>
#define sc second
#define ft first
#define PI 3.14159265
const ll N=2e5+10,MOD=998244353;
using namespace std;
ll n,t,m,a[N],i,mem[N],mp[N];
vi d[N];
ll dp (int n)
{
    ll&ret=mem[n];
    if(~ret)
        return ret;
    ret=0;
    for(auto i:d[n])
    {
        if(mp[i])
        {
            ret=max(ret,mp[i]+dp(i));
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1 ; i<N ; i++)
    {
        for (int j=i+i ; j<N; j+=i)
            d[j].push_back(i);
    }
    while(t--)
    {
        memset(mem,-1,sizeof mem);
        memset(mp,0,sizeof mp);
        cin >> n;
        ll ans=0;
        for(i=0; i<n; i++)
            cin >> a[i],mp[a[i]]++;
        for(i=0; i<n; i++)
            ans=max(ans,mp[a[i]]+dp(a[i]));
        cout<<n-ans<<endl;
    }
    return 0;
}
