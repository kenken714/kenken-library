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


# :warning: data-str/segment/bit.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#6db66d7b1b7c3dfe9d9b1c6096e86908">data-str/segment</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-str/segment/bit.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 02:10:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
ll dat[1100010];
void add(int x, ll a) {
	for (ll i = x; i <= n; i += i & -i) dat[i] += a;
}

ll sum(int x) {
	ll res = 0;
	for (int i = x; i > 0; i -= i & -i) res += dat[i];
	return res;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-str/segment/bit.cpp"
ll dat[1100010];
void add(int x, ll a) {
	for (ll i = x; i <= n; i += i & -i) dat[i] += a;
}

ll sum(int x) {
	ll res = 0;
	for (int i = x; i > 0; i -= i & -i) res += dat[i];
	return res;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

