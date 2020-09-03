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


# :heavy_check_mark: test/AOJ/DSL_1_A.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#dada0dcc232b029913f2cd4354c73c4b">test/AOJ</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/AOJ/DSL_1_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 02:29:53+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-str/unionfind/unionfind.cpp.html">data-str/unionfind/unionfind.cpp</a>
* :heavy_check_mark: <a href="../../../library/macro.cpp.html">macro.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include <bits/stdc++.h>
#include "../../macro.cpp"
#include "../../data-str/unionfind/unionfind.cpp"

int main(){
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    REP(i, q){
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) uf.unionSet(b, c);
        if (a == 1) cout << uf.findSet(b, c) << endl;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/AOJ/DSL_1_A.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include <bits/stdc++.h>
#line 2 "macro.cpp"
using namespace std;
 
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define REPO(i, n) for (ll i = 1; i <= n; i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(), n.end()
#define MOD 1000000007
#define P pair<ll, ll>
#line 1 "data-str/unionfind/unionfind.cpp"
struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
#line 6 "test/AOJ/DSL_1_A.test.cpp"

int main(){
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    REP(i, q){
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) uf.unionSet(b, c);
        if (a == 1) cout << uf.findSet(b, c) << endl;
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

