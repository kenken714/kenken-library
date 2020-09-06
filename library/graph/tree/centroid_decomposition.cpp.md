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


# :warning: graph/tree/centroid_decomposition.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#28790b6202284cbbffc9d712b59f4b80">graph/tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/tree/centroid_decomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 03:35:00+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct CentroidDecomposition {
    vector<vector<int>> g, tree;
    vector<int> sz, used;
    CentroidDecomposition(int n) : g(n), tree(n), sz(n), used(n){};
 
    void edgeset(int a, int b){
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int build(){
        return dfs(0);
    }
 
    int input(int n, bool zero = false) {
        REP(i, n - 1) {
            int a, b;
            cin >> a >> b;
            if(!zero) {
                a--; b--;
            }
            edgeset(a, b);
        }
        return build();
    }
    
    int dfs_sz(int v, int p){
        sz[v] = 1;
        for (auto& i : g[v]) {
            if (used[i] or i == p) continue;
            sz[v] += dfs_sz(i, v);
        }
        return sz[v];
    }
 
    int search(int v, int p, int mid){
        for (auto& i : g[v]) {
            if (used[i] or i == p) continue;
            if (sz[i] > mid) return search(i, v, mid);
        }
        return v;
    }
 
    int dfs(int v){
        int centroid = search(v, -1, dfs_sz(v, -1) / 2);
        used[centroid] = true;
        for (auto& i : g[centroid]) {
            if (!used[i]) tree[centroid].push_back(dfs(i));
        }
        used[centroid] = false;
        return centroid;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/tree/centroid_decomposition.cpp"
struct CentroidDecomposition {
    vector<vector<int>> g, tree;
    vector<int> sz, used;
    CentroidDecomposition(int n) : g(n), tree(n), sz(n), used(n){};
 
    void edgeset(int a, int b){
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int build(){
        return dfs(0);
    }
 
    int input(int n, bool zero = false) {
        REP(i, n - 1) {
            int a, b;
            cin >> a >> b;
            if(!zero) {
                a--; b--;
            }
            edgeset(a, b);
        }
        return build();
    }
    
    int dfs_sz(int v, int p){
        sz[v] = 1;
        for (auto& i : g[v]) {
            if (used[i] or i == p) continue;
            sz[v] += dfs_sz(i, v);
        }
        return sz[v];
    }
 
    int search(int v, int p, int mid){
        for (auto& i : g[v]) {
            if (used[i] or i == p) continue;
            if (sz[i] > mid) return search(i, v, mid);
        }
        return v;
    }
 
    int dfs(int v){
        int centroid = search(v, -1, dfs_sz(v, -1) / 2);
        used[centroid] = true;
        for (auto& i : g[centroid]) {
            if (!used[i]) tree[centroid].push_back(dfs(i));
        }
        used[centroid] = false;
        return centroid;
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

