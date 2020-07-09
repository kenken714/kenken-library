ll f[210000];
void cominit() {
    f[0] = 1;
    REP(i, 200000)f[i + 1] = f[i] * (i + 1) % MOD;
}

ll nCr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return f[n] * powmod(f[r] * f[n - r], MOD - 2) % MOD;
}

ll nPr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return f[n] * powmod(f[n - r], MOD - 2) % MOD;
}

ll nHr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return nCr(n + r - 1, r);
}