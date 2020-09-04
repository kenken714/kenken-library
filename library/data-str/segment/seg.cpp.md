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


# :x: data-str/segment/seg.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6db66d7b1b7c3dfe9d9b1c6096e86908">data-str/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-str/segment/seg.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 02:10:59+09:00




## Verified with

* :x: <a href="../../../verify/test/AOJ/DSL_2_A.test.cpp.html">test/AOJ/DSL_2_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct SegTree { //せぐつりー！
	ll sz;
	vector<ll> dat;
	SegTree(ll n) {
		sz = 1;
		while (sz < n)sz *= 2;
		dat.resize(2 * sz - 1, INF);//
	}
	void update(ll a, ll x) {
		a += sz - 1;//
		dat[a] = x;
		while (a > 0) {
			a = (a - 1) / 2;
			dat[a] = min(dat[a * 2 + 1], dat[a * 2 + 2]);//
		}
	}
	ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
		if (r < 0) r = sz;
		if (r <= a or b <= l)return INF;//
		if (a <= l and r <= b)return dat[k];//
		ll q1, q2;
		q1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		q2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(q1, q2);//
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-str/segment/seg.cpp"
struct SegTree { //せぐつりー！
	ll sz;
	vector<ll> dat;
	SegTree(ll n) {
		sz = 1;
		while (sz < n)sz *= 2;
		dat.resize(2 * sz - 1, INF);//
	}
	void update(ll a, ll x) {
		a += sz - 1;//
		dat[a] = x;
		while (a > 0) {
			a = (a - 1) / 2;
			dat[a] = min(dat[a * 2 + 1], dat[a * 2 + 2]);//
		}
	}
	ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
		if (r < 0) r = sz;
		if (r <= a or b <= l)return INF;//
		if (a <= l and r <= b)return dat[k];//
		ll q1, q2;
		q1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		q2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(q1, q2);//
	}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

