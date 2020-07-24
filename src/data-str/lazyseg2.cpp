//つよいせぐつりー！(RUQ+RAQ)
struct LazySegTree { //参照は + sz - 1;
	ll sz;
	vector<ll> node, lazy;
	vector<bool> lazyFlag;
	LazySegTree(ll n) {
		sz = 1;
		while (sz < n) sz *= 2;
		node.resize(2 * sz - 1);//
		lazy.resize(2 * sz - 1);//
		lazyFlag.resize(2 * sz - 1);
	}
	void eval(ll k, ll l, ll r) {
		if (lazyFlag[k]) {
			node[k] = lazy[k];//
			if (r - l > 1) {
				lazy[2 * k + 1] = lazy[k] / 2;//
				lazy[2 * k + 2] = lazy[k] / 2;//
				lazyFlag[2 * k + 1] = lazyFlag[2 * k + 2] = true;
			}
			lazyFlag[k] = false;
			lazy[k] = 0;//
		}
		else {
			if (lazy[k] == 0)return;
			node[k] += lazy[k];//
			if (r - l > 1) {
				lazy[2 * k + 1] += lazy[k] / 2;//
				lazy[2 * k + 2] += lazy[k] / 2;//
			}
			lazy[k] = 0;//
		}
	}
	void add(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1) {
		if (r < 0) r = sz;
		eval(k, l, r);
		if (b <= l || r <= a) return;
		if (a <= l && r <= b) {
			lazy[k] += (r - l) * x;//
			eval(k, l, r);

		}
		else {
			add(a, b, x, 2 * k + 1, l, (l + r) / 2);
			add(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = node[2 * k + 1] + node[2 * k + 2];//
		}
	}
	void update(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1) {
		if (r < 0) r = sz;
		eval(k, l, r);
		if (b <= l || r <= a) return;
		if (a <= l && r <= b) {
			lazy[k] = (r - l) * x;//	
			lazyFlag[k] = true;
			eval(k, l, r);

		}
		else {
			update(a, b, x, 2 * k + 1, l, (l + r) / 2);
			update(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = node[2 * k + 1] + node[2 * k + 2];//
		}
	}
    void add(ll a, ll x) {
		add(a, a + 1, x);
	}
	void update(ll a, ll x) {
		update(a, a + 1, x);
	}
	ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
		if (r < 0) r = sz;
		eval(k, l, r);
		if (b <= l || r <= a) return 0;//
		if (a <= l && r <= b) return node[k];
		ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
		ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return vl + vr;//
	}
	void init() {
		REPR(i, sz - 2) node[i] = node[2 * i + 1] + node[2 * i + 2];//
	}
};