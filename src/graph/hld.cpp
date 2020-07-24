struct HLD {//いつもの
	vector<ll> g[510000];
	vector<ll> sz, in, out, head, rev, par, dep; //rev = in -> index
	HLD(ll n) : sz(n), in(n), out(n), head(n), rev(n), par(n), dep(n) {};
	void dfs_sz(ll a, ll p, ll b) {
		par[a] = p;
		sz[a] = 1;
		dep[a] = b;
		if (g[a].size() && g[a][0] == p) swap(g[a][0], g[a].back());
		for (auto& to : g[a]) {
			if (to == p)continue;
			dfs_sz(to, a, b + 1);
			sz[a] += sz[to];
			if (sz[g[a][0]] < sz[to])swap(g[a][0], to);
		}
	}
	void dfs_hld(ll a, ll p, ll& t) {
		in[a] = t++;
		rev[in[a]] = a;
		for (auto& to : g[a]) {
			if (to == p)continue;
			head[to] = (g[a][0] == to ? head[a] : to);
			dfs_hld(to, a, t);
		}
		out[a] = t;
	}
	void edgeset(ll a, ll b) {
		g[a].push_back(b);
		g[b].push_back(a);
	}
	void build() {
		dfs_sz(0, -1, 0);
		ll t = 0;
		dfs_hld(0, -1, t);
	}
	void input(ll n) {
		REP(i, n - 1) {
			ll a, b;
			cin >> a >> b;
			a--; b--;
			edgeset(a, b);
		}
		build();
	}
	ll la(ll a, ll x) {
		while (1) {
			ll h = head[a];
			if (in[a] - x >= in[h])return rev[in[a] - x];
			x -= in[a] - in[h] + 1;
			a = par[h];
		}
	}
	ll lca(ll a, ll b) {
		for (;; b = par[head[b]]) {
			if (in[a] > in[b])swap(a, b);
			if (head[a] == head[b])return a;
		}
	}
	template< typename Q, typename F >
	ll query(ll a, ll b, ll ti, const Q& q, const F& f, bool edge = false) {
		ll l = ti, r = ti;
		for (;; b = par[head[b]]) {
			if (in[a] > in[b])swap(a, b), swap(l, r);
			if (head[a] == head[b])break;
			l = f(q(in[head[b]], in[b] + 1), l);
		}
		return f(f(q(in[a] + edge, in[b] + 1), l), r);
	}
	template < typename Q >
	void addpath(ll a, ll b, ll x, const Q& q, bool edge = false) { //path
		for (;; b = par[head[b]]) {
			if (in[a] > in[b])swap(a, b);
			if (head[a] == head[b])break;
			q(in[head[b]], in[b] + 1, x);
		}
		return q(in[a] + edge, in[b] + 1, x);
	}
	template < typename Q >
	void addst(ll a, ll x, const Q& q) { //subtree
		q(in[a], out[a], x);
	}
};