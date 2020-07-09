#define PP pair<ll, P>
ll d[110000][MAX]; // 結果
struct edge { ll to, cost; };
vector<edge> g[110000]; //隣接リスト to, cost

ll solve_next(ll v, ll now) { //状態の遷移を書く
	return v;
}
void dijkstra(ll a) { //すごいだいくすとら！
	priority_queue<PP, vector<PP>, greater<PP> > q; // cost, to, 条件
	REP(i, n)fill(d[i], d[i] + MAX, INF);

	d[a][init] = 0;
	q.push(PP(0, P(a, init)));
	while (!q.empty()) {
		PP p = q.top();
		q.pop();
		ll v = p.second.first, now = p.second.second;
		if (d[v][now] < p.first) continue;
		REP(i, g[v].size()) {
			edge e = g[v][i];
			ll next = solve_next(v, now);
			if (d[e.to][next] > d[v][now] + e.cost) {
				d[e.to][next] = d[v][now] + e.cost;
				q.push(PP(d[e.to][next], P(e.to, next)));
			}
		}
	}
}