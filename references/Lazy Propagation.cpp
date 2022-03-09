static void check(int p,int s,int e)
{
    if(lazy[p]!=0)
    {
        seg[p] += lazy[p];
        if(s!=e)
        {
            lazy[2*p] += lazy[p];
            lazy[2*p+1] += lazy[p];
        }
        lazy[p] = 0;
    }
}
static void build(int p,int s,int e)
{
    check(p,s,e);

    if(s==e)
    {
        seg[p] = a[s];
        return;
    }

    build(2*p,s,(s+e)/2);
    build(2*p+1,(s+e)/2+1,e);

    seg[p] = min(seg[2*p], seg[2*p+1]);
}
static void update(int p,int s,int e,int a,int b,int v)
{
    check(p,s,e);

    if(s>=a && e<=b)
    {
        seg[p] += v;

        if(s!=e)
        {
            lazy[2*p] += v;
            lazy[2*p+1] += v;
        }

        return;
    }

    if(s>b || e<a)
        return;

    update(2*p,s,(s+e)/2,a,b,v);
    update(2*p+1,(s+e)/2+1,e,a,b,v);

    seg[p] = min(seg[2*p],seg[2*p+1]);
}

static int get(int p,int s,int e,int a,int b)
{
    check(p,s,e);

    if(s>=a && e<=b)
        return seg[p];

    if(s>b || e<a)
        return 0;

    return min(get(2*p,s,(s+e)/2,a,b), get(2*p+1,(s+e)/2+1,e,a,b));
}
