ll dat[1100010];
void add(int x, ll a) {
	for (ll i = x; i <= 1000100; i += i & -i) dat[i] += a;
}

ll sum(int x) {
	ll res = 0;
	for (int i = x; i > 0; i -= i & -i) res += dat[i];
	return res;
}