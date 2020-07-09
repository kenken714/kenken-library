ll f[210000];
void cominit(ll mod = 1e9+7) {
    f[0] = 1;
    REP(i, 200000)f[i + 1] = f[i] * (i + 1) % mod;
}

ll nCr(ll n, ll r, ll mod = 1e9+7) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return f[n] * powmod(f[r] * f[n - r], mod - 2) % mod;
}

ll nPr(ll n, ll r, ll mod = 1e9+7) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return f[n] * powmod(f[n - r], mod - 2) % mod;
}

ll nHr(ll n, ll r, ll mod = 1e9+7) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return nCr(n + r - 1, r);
}