queue<P> q;
ll d[][] = {};
bool used[][] = {};
q.push(P(i, j));
used[i][j] = true;
while (!q.empty()) {
	P now = q.front();
	q.pop();
	ll a = now.first, b = now.second;
	REP(nxt, 4) {
		ll x = now.first + v1[nxt], y = now.second + v2[nxt];
		if (0 > x or x >= h or 0 > y or y >= w or used[x][y]) continue;
		//if(s[x][y] == '#') continue;
		used[x][y] = true;
		d[x][y] = d[a][b] + 1;
		q.push(P(x, y));
	}
}