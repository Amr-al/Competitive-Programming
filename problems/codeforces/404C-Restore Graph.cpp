#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 1e5+5,MOD=1e9+7;
ll n,k,a,b,cnt=0,mx=-1;
deque<int>v[N];
vector<pair<int,int> > ans;
map<int,int> mp;
int main(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i){
        cin >> a;
        mx=max(a,mx);
        if(!a)
            cnt++;
        v[a].push_back(i);
    }
    if(cnt>=2)
        return cout << -1,0;
    for(int i=0; i<mx; i++){
        if(v[i].size()*k <v[i+1].size() || v[i+1].size()==0)
            return cout << -1,0;
        for(int j=0; j<v[i+1].size(); j++){
            ans.push_back({v[i].front(),v[i+1][j]});
            mp[v[i+1][j]]++;
            mp[v[i].front()]++;
            if(mp[v[i].front()]==k)
                v[i].pop_front();
        }
    }
    for(int i=0;i<=mx;i++) v[i].clear();
    for(int i=0;i<ans.size();i++){
            v[ans[i].first].push_back(ans[i].second);
            v[ans[i].second].push_back(ans[i].first);
    }
    for(int i=0;i<=mx;i++) if(v[i].size()>k) return cout << -1,0;
    cout << ans.size() <<endl;
    for(int i=0; i<ans.size(); i++)
        cout << ans[i].first << ' '<<ans[i].second << endl;
    return 0;
}
