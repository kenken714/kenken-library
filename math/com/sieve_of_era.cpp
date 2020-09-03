vector<ll> era(ll n) {
	vector<bool> ok(n + 1, true);
	ok[0] = false;
	ok[1] = false;
	vector<ll> res;
	for (ll i = 2; i <= sqrt(n); ++i) {
		if (IsPrime(i)) {
			for (ll j = i * i; j <= n; j += i) ok[j] = false;
		}
	}
	FOR(i, 2, n + 1)if (ok[i])res.push_back(i);
	return res;
}