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


# :warning: graph/shotest/dijkstra.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0c95a70ca7e401d248a35bda820df083">graph/shotest</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/shotest/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 02:10:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/shotest/dijkstra.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

