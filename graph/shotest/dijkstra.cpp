ll d[210000]; // 結果
struct edge { ll to, cost; };
vector<edge> g[210000]; //隣接リスト to, cost
void dijkstra(ll a) { //だいくすとら！
	priority_queue<P, vector<P>, greater<P> > q;
	fill(d, d + n, INF);
	d[a] = 0;
	q.push(P(0, a));
	while (!q.empty()) {
		P p = q.top();
		q.pop();
		ll v = p.second;
		if (d[v] < p.first) continue;
		REP(i, g[v].size()) {
			edge e = g[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				q.push(P(d[e.to], e.to));
			}
		}
	}
}