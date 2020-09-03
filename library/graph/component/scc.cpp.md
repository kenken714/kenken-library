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


# :warning: graph/component/scc.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#11d7325260d2fe77abd8dca04677cb88">graph/component</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/component/scc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 02:10:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/component/scc.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

