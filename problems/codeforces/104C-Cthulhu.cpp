#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long
#define pi pair<int,int>
#define vi vector<int>
#define sc second
#define ft first
#define N 50000+7
using namespace std;
int nodes,edges;
int p[N];
vector<pi>v;
int find_set(int u){
    if(p[u]==u) return u;
    return p[u] = find_set(p[u]);
}
void make_set(){
    for(int i=0;i<=nodes;i++) p[i]=i;
}
void union_set(int a ,int b){
    a=find_set(a);  
    b=find_set(b);
    if(a!=b)
      p[b]=a;
}
int main()
{
     cin >> nodes >> edges ;
     for(int i=0;i<edges;i++){
         int a,b; cin >> a >> b;
         v.pb({a,b});
     }
     make_set(); int cnt=0;
     for(int i=0;i<v.size();i++){
         int stp=find_set(v[i].ft);
         int enp=find_set (v[i].sc);
         if(stp!=enp){
             union_set(stp,enp);
         }
         else cnt++; 
     }
      if( cnt==1 && nodes==edges) cout <<"FHTAGN!";
      else cout << "NO";
        printf("\n"); 
	return 0;
}
