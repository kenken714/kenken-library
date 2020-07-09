//トポロジカルソート
vector<ll> in(n), ans; // 答え
queue<ll> que;
//入次数
REP(i, n) { //隣接リストの長さ
	REP(j, g[i].size()) { //隣接リストの変数名
		in[g[i][j]]++;
	}
}
REP(i, n) if (in[i] == 0)que.push(i);
while (!que.empty()) {
	ll now = que.front();
	ans.push_back(now);
	que.pop();
	REP(i, g[now].size()) {
		in[g[now][i]]--;
		if (in[g[now][i]] == 0) {
			que.push(g[now][i]);
		}
	}
}