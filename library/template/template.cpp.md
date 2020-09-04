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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :question: template/template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#66f6181bcb4cff4cd38fbc804a036db6">template</a>
* <a href="{{ site.github.repository_url }}/blob/master/template/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-04 21:52:34+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/AOJ/DSL_1_A.test.cpp.html">test/AOJ/DSL_1_A.test.cpp</a>
* :x: <a href="../../verify/test/AOJ/DSL_2_A.test.cpp.html">test/AOJ/DSL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/AOJ/DSL_2_B.test.cpp.html">test/AOJ/DSL_2_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "template/template.cpp"
#include <bits/stdc++.h>
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

