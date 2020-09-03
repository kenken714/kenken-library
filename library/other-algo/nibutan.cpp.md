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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: other-algo/nibutan.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#af417960dab45403316179de8d54f2fe">other-algo</a>
* <a href="{{ site.github.repository_url }}/blob/master/other-algo/nibutan.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 02:10:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
bool solve(ll index, ll key) { //条件判定
	if (true) return true; //ここに条件を入れる
	else return false;
}

ll nibutan(ll key = 0) { //ちゃろー！

	ll ng = -1; //最大値ならs.size()
	ll ok = (ll)s.size(); // 最大値なら0

	while (abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;

		if (solve(mid, key)) ok = mid;
		else ng = mid;
	}
	return ok; //満たさない最大ならng
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "other-algo/nibutan.cpp"
bool solve(ll index, ll key) { //条件判定
	if (true) return true; //ここに条件を入れる
	else return false;
}

ll nibutan(ll key = 0) { //ちゃろー！

	ll ng = -1; //最大値ならs.size()
	ll ok = (ll)s.size(); // 最大値なら0

	while (abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;

		if (solve(mid, key)) ok = mid;
		else ng = mid;
	}
	return ok; //満たさない最大ならng
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

