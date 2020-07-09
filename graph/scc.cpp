ll n;
vector<ll> g[110000];
vector<ll> rg[110000];
vector<ll> vs;
bool used[110000];
ll cmp[110000];
void add_edge(ll from, ll to) {
	g[from].push_back(to);
	rg[to].push_back(from);
}

void dfs(ll v) {
	used[v] = true;
	REP(i, g[v].size()) if (!used[g[v][i]]) dfs(g[v][i]);
	vs.push_back(v);
}

void rdfs(ll v, ll k) {
	used[v] = true;
	cmp[v] = k;
	REP(i, rg[v].size()) if (!used[rg[v][i]]) rdfs(rg[v][i], k);
}

ll scc() {
	memset(used, 0, sizeof(used));
	REP(i, n) if (!used[i])dfs(i);
	memset(used, 0, sizeof(used));
	ll k = 0;
	REPR(i, vs.size() - 1) if (!used[vs[i]]) rdfs(vs[i], k++);
	return k;
}