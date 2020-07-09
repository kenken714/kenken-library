vector<ll> f, inv, finv;
const ll mod = MOD;
void cominit(ll n = 210000) {
    f.resize(n + 1);
    inv.resize(n + 1);
    finv.resize(n + 1);
    f[0] = f[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    FOR(i, 2, n + 1) {
        f[i] = f[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

ll nCr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return f[n] * (finv[r] * finv[n - r] % mod) % mod;
}

ll nPr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return f[n] * finv[n - r] % mod;
}

ll nHr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return nCr(n + r - 1, r);
}