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


# :warning: graph/other/kruskal.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#7bdf4bef6792afd2baf0aea42eec3899">graph/other</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/other/kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 02:10:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/other/kruskal.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

