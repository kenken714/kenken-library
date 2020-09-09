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


# :warning: graph/component/two_edge_connected_components.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#11d7325260d2fe77abd8dca04677cb88">graph/component</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/component/two_edge_connected_components.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 04:45:06+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct TwoEdgeConnectedComponents : LowLink{
    using LowLink::LowLink;
    vector<int> comp;
    vector<vector<int>> tree;
    vector<vector<int>> group;

    void build(){
        LowLink::build();
        comp.resize(g.size(), -1);
        int t = 0;
        REP(i, g.size()){
            if(comp[i] == -1)dfs(i, -1, t);
        }

        group.resize(t);
        REP(i, g.size()){
            group[comp[i]].push_back(i);
        }
        tree.resize(t);
        for (auto& i : bridge) {
            tree[comp[i.first]].push_back(comp[i.second]);
            tree[comp[i.second]].push_back(comp[i.first]);
        }

    }
    void dfs(int v, int p, int &t){
        if (p != -1 and ord[p] >= low[v]) comp[v] = comp[p];
        else comp[v] = t++;
        for (auto& i : g[v]) {
            if (comp[i] == -1) dfs(i, v, t);
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/component/two_edge_connected_components.cpp"
struct TwoEdgeConnectedComponents : LowLink{
    using LowLink::LowLink;
    vector<int> comp;
    vector<vector<int>> tree;
    vector<vector<int>> group;

    void build(){
        LowLink::build();
        comp.resize(g.size(), -1);
        int t = 0;
        REP(i, g.size()){
            if(comp[i] == -1)dfs(i, -1, t);
        }

        group.resize(t);
        REP(i, g.size()){
            group[comp[i]].push_back(i);
        }
        tree.resize(t);
        for (auto& i : bridge) {
            tree[comp[i.first]].push_back(comp[i.second]);
            tree[comp[i.second]].push_back(comp[i.first]);
        }

    }
    void dfs(int v, int p, int &t){
        if (p != -1 and ord[p] >= low[v]) comp[v] = comp[p];
        else comp[v] = t++;
        for (auto& i : g[v]) {
            if (comp[i] == -1) dfs(i, v, t);
        }
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

