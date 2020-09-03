---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: graph/shotest/ex_dijkstra.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0c95a70ca7e401d248a35bda820df083">graph/shotest</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/shotest/ex_dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 02:10:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/shotest/ex_dijkstra.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

