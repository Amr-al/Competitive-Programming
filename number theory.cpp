//Important Series:
//sum of first n integers = n * (n + 1) / 2
//    1 + 2 + 3 = 3 * 4 / 2
//sum of first n odd integers = n^2
//    1 + 3 + 5 = 3^2
//sum of first n powers of two = (2^n) - 1
//    1 + 2 + 4 = (2^3) - 1
//sum of arithmetic series
//sum of geometric series

/**
  * Counting principles
      - Product Rule
      - Sum Rule (Inclusion-Exclusion)
      - Division Rule
  * Permutations
  * Combinations
  */

#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

const int N = 1e6 + 5, MOD = 1e9 + 7;

lld fact[N];
void calcFactorial(){
    fact[0] = 1;
    for(int i = 1; i < N; ++i){
        fact[i] = (i * fact[i-1]) % MOD;
        //cout << fact[i] << " ";
    }
}

lld power(lld b, lld po, lld mod){
    lld ret = 1;
    while(po){
        if(po & 1) ret = (ret * b) % mod;
        b = (b * b) % mod;
        po >>= 1;
    }
    return ret;
}

lld mulInv(lld x, lld mod){
    return power(x, mod - 2, mod);
}

//- - - -
//6 5 4 3
//6! / 2!
//n numbers, k places
//P(n, k) = n! / (n-k)!
//If numbers can be repeated -> n^k

lld P(lld n, lld k){    /// O(log(MOD))
    return (fact[n] * mulInv(fact[n-k], MOD)) % MOD;
}

//C(n, k) = P(n, k) / k!
//        = n! / ((n-k)! * k!)
lld C(lld n, lld k){    /// O(log(MOD))
    //return (P(n, k) * mulInv(fact[k], MOD)) % MOD;
    return (fact[n] * mulInv(fact[n-k] * fact[k] % MOD, MOD)) % MOD;
}

int main()
{
    /*
    123
    132
    213
    231
    312
    321
    */
    int n = 3;
    int a[n] = {3, 1, 2};
    sort(a, a + n);
    //reverse(a, a + n);
    do{                                 /// O(n!)
        for(int i = 0; i < n; ++i)
            cout << a[i] << " ";
        puts("");
    }while(next_permutation(a, a + n)); //prev_permutation

    puts("");

    calcFactorial();
    cout << 10 * 9 * 8 << endl;
    cout << P(10, 3) << endl;
    cout << C(10, 3) << endl;

    lld C[103][103];
    /// C(n, k) = C(n-1, k-1) + C(n-1, k)
    /* Pascal's Triangle, i = row, j = col */
    for(int i = 1; i <= 100; ++i){  /// O(n^2)
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; ++j){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
    cout << C[10][3] << endl;

    /// Note1: C(n, k) = C(n, n-k)
    /// Note2: C(n, 0) + C(n, 1) + C(n, 2) ..... C(n, n) = 2^n

    return 0;
}
