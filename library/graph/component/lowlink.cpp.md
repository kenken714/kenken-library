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


# :warning: graph/component/lowlink.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#11d7325260d2fe77abd8dca04677cb88">graph/component</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/component/lowlink.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 04:45:06+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct LowLink{
    vector<vector<int>> g;
    vector<int> ord, low, articulation;
    vector<P> bridge;
    vector<bool> used;
    LowLink(int n) : g(n){};
    LowLink(vector<vector<int>> g) : g(g){};
    
    void edgeset(int a, int b){
        g[a].push_back(b);
        g[b].push_back(a);
    }

    void dfs(int v, int p, int &t){
        used[v] = true;
        ord[v] = t++;   
        low[v] = ord[v];
        bool ar = false, ck = false;
        int sub = 0;
        for (auto& i : g[v]) {
            if (i == p and !exchange(ck, true)) continue;
            if(!used[i]){
                dfs(i, v, t);
                sub++;
                low[v] = min(low[v], low[i]);
                if (p != -1 and low[i] >= ord[v]) ar = true;
                if (low[i] > ord[v]) bridge.push_back(P(v, i));
            }
            else{
                low[v] = min(low[v], ord[i]);
            }
        }
        if (p == -1 and sub >= 2) ar = true;
        if (ar) articulation.push_back(v);
    }

    void build(){
        ord.resize(g.size());
        low.resize(g.size());
        used.resize(g.size());
        int k = 0;
        REP(i, (int)g.size()){
            if(!used[i]) dfs(i, -1, k);
        }   
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/component/lowlink.cpp"
struct LowLink{
    vector<vector<int>> g;
    vector<int> ord, low, articulation;
    vector<P> bridge;
    vector<bool> used;
    LowLink(int n) : g(n){};
    LowLink(vector<vector<int>> g) : g(g){};
    
    void edgeset(int a, int b){
        g[a].push_back(b);
        g[b].push_back(a);
    }

    void dfs(int v, int p, int &t){
        used[v] = true;
        ord[v] = t++;   
        low[v] = ord[v];
        bool ar = false, ck = false;
        int sub = 0;
        for (auto& i : g[v]) {
            if (i == p and !exchange(ck, true)) continue;
            if(!used[i]){
                dfs(i, v, t);
                sub++;
                low[v] = min(low[v], low[i]);
                if (p != -1 and low[i] >= ord[v]) ar = true;
                if (low[i] > ord[v]) bridge.push_back(P(v, i));
            }
            else{
                low[v] = min(low[v], ord[i]);
            }
        }
        if (p == -1 and sub >= 2) ar = true;
        if (ar) articulation.push_back(v);
    }

    void build(){
        ord.resize(g.size());
        low.resize(g.size());
        used.resize(g.size());
        int k = 0;
        REP(i, (int)g.size()){
            if(!used[i]) dfs(i, -1, k);
        }   
    }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

