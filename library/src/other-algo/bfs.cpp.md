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


# :warning: src/other-algo/bfs.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e9fd3da3699d4799bc832d6181386d1b">src/other-algo</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/other-algo/bfs.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-25 01:41:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/other-algo/bfs.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

