ll powmod(ll a, ll b, ll mod = 1e9+7) {
	a %= mod;
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1)res = res * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return res;
}