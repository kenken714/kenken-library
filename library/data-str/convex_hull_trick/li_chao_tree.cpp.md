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


# :warning: data-str/convex_hull_trick/li_chao_tree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#b4d4587b4d59861af2d90d43b6d76fd9">data-str/convex_hull_trick</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-str/convex_hull_trick/li_chao_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 14:47:16+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
template <typename T>
struct LiChaoTree {
    struct Line{
        T a, b;
        Line(T a, T b) : a(a), b(b){};
        inline T get(T x) const { return a * x + b; };
    };

    vector<Line> dat;
    vector<T> pos;
    int sz;

    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        dat.assign(2 * sz - 1, Line(0, INF));
    }

    int index(T x) const { return lower_bound(ALL(pos), x) - pos.begin(); };

    LiChaoTree(int n){
        init(n);
        REP(i, sz) pos.push_back(i);
    }

    LiChaoTree(const vector<T> &a) : pos(a){
        sort(ALL(pos));
        pos.erase(unique(ALL(pos)), pos.end());
        int n = pos.size();
        init(n);
        while((int)pos.size() < sz) pos.push_back(pos.back() + 1);
    }

    void add_line(Line a, int k, int l, int r){
        int m = (l + r) / 2;
        bool x = a.get(pos[l]) < dat[k].get(pos[l]);
        bool y = a.get(pos[m]) < dat[k].get(pos[m]);
        if (y) swap(dat[k], a);
        if (r - l <= 1) return;
        if (x != y) add_line(a, 2 * k + 1, l, m);
        else add_line(a, 2 * k + 2, m, r);
    }

    void add_line(T &a, T &b){
        Line li(a, b);
        add_line(li, 0, 0, sz);
    }

    void add_segment(T &x, T &y, int a, int b){
        Line li(x, y);
        int l = a + sz, r = b + sz, a0 = a, b0 = b, ns = 1;
        while(l < r){
            if(r & 1){
                r--;
                b0 -= ns;
                add_line(li, r - 1, b0, b0 + ns);
            }
            if(l & 1){
                add_line(li, l - 1, a0, a0 + ns);
                l++;
                a0 += ns;
            }
            l >>= 1;
            r >>= 1;
            ns <<= 1;
        }
    }

    T query(int x){
        T npos = pos[x];
        x += sz - 1;
        T res = dat[x].get(npos);
        while(x > 0){
            x = (x - 1) / 2;
            res = min(res, dat[x].get(npos));
        }
        return res;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-str/convex_hull_trick/li_chao_tree.cpp"
template <typename T>
struct LiChaoTree {
    struct Line{
        T a, b;
        Line(T a, T b) : a(a), b(b){};
        inline T get(T x) const { return a * x + b; };
    };

    vector<Line> dat;
    vector<T> pos;
    int sz;

    void init(int n){
        sz = 1;
        while (sz < n) sz *= 2;
        dat.assign(2 * sz - 1, Line(0, INF));
    }

    int index(T x) const { return lower_bound(ALL(pos), x) - pos.begin(); };

    LiChaoTree(int n){
        init(n);
        REP(i, sz) pos.push_back(i);
    }

    LiChaoTree(const vector<T> &a) : pos(a){
        sort(ALL(pos));
        pos.erase(unique(ALL(pos)), pos.end());
        int n = pos.size();
        init(n);
        while((int)pos.size() < sz) pos.push_back(pos.back() + 1);
    }

    void add_line(Line a, int k, int l, int r){
        int m = (l + r) / 2;
        bool x = a.get(pos[l]) < dat[k].get(pos[l]);
        bool y = a.get(pos[m]) < dat[k].get(pos[m]);
        if (y) swap(dat[k], a);
        if (r - l <= 1) return;
        if (x != y) add_line(a, 2 * k + 1, l, m);
        else add_line(a, 2 * k + 2, m, r);
    }

    void add_line(T &a, T &b){
        Line li(a, b);
        add_line(li, 0, 0, sz);
    }

    void add_segment(T &x, T &y, int a, int b){
        Line li(x, y);
        int l = a + sz, r = b + sz, a0 = a, b0 = b, ns = 1;
        while(l < r){
            if(r & 1){
                r--;
                b0 -= ns;
                add_line(li, r - 1, b0, b0 + ns);
            }
            if(l & 1){
                add_line(li, l - 1, a0, a0 + ns);
                l++;
                a0 += ns;
            }
            l >>= 1;
            r >>= 1;
            ns <<= 1;
        }
    }

    T query(int x){
        T npos = pos[x];
        x += sz - 1;
        T res = dat[x].get(npos);
        while(x > 0){
            x = (x - 1) / 2;
            res = min(res, dat[x].get(npos));
        }
        return res;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

