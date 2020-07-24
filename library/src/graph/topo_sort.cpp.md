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


# :warning: src/graph/topo_sort.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5442c8f317d712204bf06ed26672e17c">src/graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/graph/topo_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-25 01:41:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/graph/topo_sort.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

