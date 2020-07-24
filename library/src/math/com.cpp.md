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


# :warning: src/math/com.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#fb2ef479237c7a939531a404fd0e5cb7">src/math</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/math/com.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-25 01:41:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
vector<ll> f, inv, finv;
const ll mod = MOD;
void cominit(ll n = 210000) {
    f.resize(n + 1);
    inv.resize(n + 1);
    finv.resize(n + 1);
    f[0] = f[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    FOR(i, 2, n + 1) {
        f[i] = f[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

ll nCr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return f[n] * (finv[r] * finv[n - r] % mod) % mod;
}

ll nPr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return f[n] * finv[n - r] % mod;
}

ll nHr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return nCr(n + r - 1, r);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/math/com.cpp"
vector<ll> f, inv, finv;
const ll mod = MOD;
void cominit(ll n = 210000) {
    f.resize(n + 1);
    inv.resize(n + 1);
    finv.resize(n + 1);
    f[0] = f[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    FOR(i, 2, n + 1) {
        f[i] = f[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

ll nCr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return f[n] * (finv[r] * finv[n - r] % mod) % mod;
}

ll nPr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return f[n] * finv[n - r] % mod;
}

ll nHr(ll n, ll r) {
    if (n < r)return 0;
    if (n < 0 or r < 0)return 0;
    return nCr(n + r - 1, r);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

