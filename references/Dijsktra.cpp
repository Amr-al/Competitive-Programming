vector< pi > v[N];
void Dijsktra(int src=1){
    p_q<pi , vector<pi> ,greater<pi> >q;
    fill(p,p+N,-1); fill(dis,dis+N,INF);
    dis[src]=0; q.push({0,src});
    while(!q.empty()){
        int u=q.top().sc; q.pop();
        for(pi it : v[u]){
            if(dis[u]+it.sc < dis[it.ft]){
                dis[it.ft]=dis[u]+it.sc;
                p[it.ft]=u;
                q.push({dis[it.ft],it.ft});
            }
        }
    }
    
}
