void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    }
    int tm = (tl + tr) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    t[v] = t[v*2] + t[v*2+1];
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
       update(v*2, tl, tm, pos, new_val);
    else
       update(v*2+1, tm+1, tr, pos, new_val);
    t[v] = t[v*2] + t[v*2+1];
}
int get(int p,int s,int e,int a,int b) {
        if(s>=a && e<=b)
            return seg[p];
        
        if(s>b || e<a)
            return INF; 
        
        return min(get(2*p,s,(s+e)/2,a,b), get(2*p+1,(s+e)/2+1,e,a,b));
 }
