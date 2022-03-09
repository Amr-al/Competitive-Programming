void fact()
{
    factorial[0] = 1;
    for (int i = 1; i < N; i++)
        factorial[i] = factorial[i - 1] * i % MOD;
}
void mul()
{
    inv[1] = 1;
    for(int i = 2; i < N; ++i)
        inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
    for(int i = 2; i < N; ++i)
        inv[i] =  inv[i] * inv[i - 1] % MOD;
}
ll nCr(ll n,ll r)  // O(log MOD)
{
    if(r>n) return 0;
    if(!r) return 1;
    return factorial[n] * (inv[r] * inv[n-r] % MOD ) % MOD;
}
ll mul(){
    inv[0] = 1;
    ll tmp = fb(31,MOD-2,MOD);
    for(int i = 1; i < N ;++i)
    {
        inv[i] = inv[i-1] * tmp % MOD;
    }
}
