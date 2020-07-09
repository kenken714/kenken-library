ll powmod(ll a, ll b) {
	a %= MOD;
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1)res = res * a % MOD;
		a = a * a % MOD;
		b /= 2;
	}
	return res;
}