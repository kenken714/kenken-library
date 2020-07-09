struct Edge {
	int a, b, cost;
	bool operator<(const Edge& o) const {
		return cost < o.cost;
	}
};

vector<Edge> es;  // 隣接リスト a, b, cost

int kruskal() {
	sort(es.begin(), es.end());
	UnionFind uf(210000);
	int min_cost = 0;
	REP(ei, es.size()) {
		Edge& e = es[ei];
		if (!uf.findSet(e.a, e.b)) {
			min_cost += e.cost;
			uf.unionSet(e.a, e.b);
		}
	}
	return min_cost;
}