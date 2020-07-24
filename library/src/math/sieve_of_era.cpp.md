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


# :warning: src/math/sieve_of_era.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fb2ef479237c7a939531a404fd0e5cb7">src/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/math/sieve_of_era.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-25 01:41:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<ll> era(ll n) {
	vector<bool> ok(n + 1, true);
	ok[0] = false;
	ok[1] = false;
	vector<ll> res;
	for (ll i = 2; i <= sqrt(n); ++i) {
		if (IsPrime(i)) {
			for (ll j = i * i; j <= n; j += i) ok[j] = false;
		}
	}
	FOR(i, 2, n + 1)if (ok[i])res.push_back(i);
	return res;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/math/sieve_of_era.cpp"
vector<ll> era(ll n) {
	vector<bool> ok(n + 1, true);
	ok[0] = false;
	ok[1] = false;
	vector<ll> res;
	for (ll i = 2; i <= sqrt(n); ++i) {
		if (IsPrime(i)) {
			for (ll j = i * i; j <= n; j += i) ok[j] = false;
		}
	}
	FOR(i, 2, n + 1)if (ok[i])res.push_back(i);
	return res;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
