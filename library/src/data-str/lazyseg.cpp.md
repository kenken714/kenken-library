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


# :warning: src/data-str/lazyseg.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dcfab7a28915543077d1e3e3e6bbe5ad">src/data-str</a>
* <a href="{{ site.github.repository_url }}/blob/master/src/data-str/lazyseg.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-25 01:41:42+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
//つよいせぐつりー！
struct LazySegTree { //参照は i + sz - 1 だよ～;
    ll sz;
    vector<ll> node, lazy;
    vector<bool> lazyFlag;
    LazySegTree(ll n) {
        sz = 1;
        while (sz < n) sz *= 2;
        node.resize(2 * sz - 1);//
        lazy.resize(2 * sz - 1);//
        lazyFlag.resize(2 * sz - 1);
    }
    void eval(ll k, ll l, ll r) {
        if (lazyFlag[k]) {
            node[k] += lazy[k];//
            if (r - l > 1) {
                lazy[2 * k + 1] += lazy[k] / 2;//
                lazy[2 * k + 2] += lazy[k] / 2;//
                lazyFlag[2 * k + 1] = lazyFlag[2 * k + 2] = true;
            }
            lazyFlag[k] = false;
            lazy[k] = 0;//
        }
    }
    void update(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1) {
        if (r < 0) r = sz;
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x;//
            lazyFlag[k] = true;
            eval(k, l, r);

        }
        else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];//
        }
    }
    void update(ll a, ll x) {
        update(a, a + 1, x);
    }
    ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
        if (r < 0) r = sz;
        eval(k, l, r);
        if (b <= l || r <= a) return 0;//
        if (a <= l && r <= b) return node[k];
        ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;//
    }
    void init() {
        REPR(i, sz - 2) node[i] = node[2 * i + 1] + node[2 * i + 2];//
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "src/data-str/lazyseg.cpp"
//つよいせぐつりー！
struct LazySegTree { //参照は i + sz - 1 だよ～;
    ll sz;
    vector<ll> node, lazy;
    vector<bool> lazyFlag;
    LazySegTree(ll n) {
        sz = 1;
        while (sz < n) sz *= 2;
        node.resize(2 * sz - 1);//
        lazy.resize(2 * sz - 1);//
        lazyFlag.resize(2 * sz - 1);
    }
    void eval(ll k, ll l, ll r) {
        if (lazyFlag[k]) {
            node[k] += lazy[k];//
            if (r - l > 1) {
                lazy[2 * k + 1] += lazy[k] / 2;//
                lazy[2 * k + 2] += lazy[k] / 2;//
                lazyFlag[2 * k + 1] = lazyFlag[2 * k + 2] = true;
            }
            lazyFlag[k] = false;
            lazy[k] = 0;//
        }
    }
    void update(ll a, ll b, ll x, ll k = 0, ll l = 0, ll r = -1) {
        if (r < 0) r = sz;
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x;//
            lazyFlag[k] = true;
            eval(k, l, r);

        }
        else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = node[2 * k + 1] + node[2 * k + 2];//
        }
    }
    void update(ll a, ll x) {
        update(a, a + 1, x);
    }
    ll query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
        if (r < 0) r = sz;
        eval(k, l, r);
        if (b <= l || r <= a) return 0;//
        if (a <= l && r <= b) return node[k];
        ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return vl + vr;//
    }
    void init() {
        REPR(i, sz - 2) node[i] = node[2 * i + 1] + node[2 * i + 2];//
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

