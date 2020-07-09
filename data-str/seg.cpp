struct SegTree { //せぐつりー！
	ll sz;
	vector<ll> dat;
	SegTree(ll n) {
		sz = 1;
		while (sz < n)sz *= 2;
		dat.resize(2 * sz - 1, INF);//
	}
	void update(ll a, ll x) {
		a += sz - 1;//
		dat[a] = x;
		while (a > 0) {
			a = (a - 1) / 2;
			dat[a] = min(dat[a * 2 + 1], dat[a * 2 + 2]);//
		}
	}
	ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
		if (r < 0) r = sz;
		if (r <= a or b <= l)return INF;//
		if (a <= l and r <= b)return dat[k];//
		ll q1, q2;
		q1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		q2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(q1, q2);//
	}
};