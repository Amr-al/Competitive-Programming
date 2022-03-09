#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define sc second
#define ft first
#define p_q priority_queue
#define INF 10000000000
using namespace std;
const ll MOD=1e9+7;
const ll N=2e5+7;
ll n , m , xs ,xf , ys ,yf ;
int dx[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
map<pl,int>vis,ans,mp;
bool valid(ll i,ll j){
    return(!vis[{i,j}] && mp[{i,j}] );
}
void bfs(int i , int j){
    vis[{i,j}]++;
    queue<pl>q;
    q.push({i,j}); 
    for(int cnt=1;(!q.empty());cnt++){
        int sz=q.size();
        while(sz--){
        pi u=q.front(); q.pop(); 
        for(int ii=0;ii<8;ii++){
            ll x=u.ft+dx[ii],y=u.sc+dy[ii];
            if(valid(x,y)){
                vis[{x,y}]++;
                q.push({x,y});
                ans[{x,y}]=cnt;
            }
        }
    }
    }
    
}
int main(){
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> xs >> ys >> xf >> yf >> n ;
    for(int i=0;i<n;i++){
        int r,a,b; cin >> r >> a >>b;
           for(int j=a;j<=b;j++) mp[{r,j}]++;
    }
    bfs(xs,ys);
    if(ans[{xf,yf}]? cout << ans[{xf,yf}] <<'\n': cout << -1 <<'\n');
    
	return 0;
}
