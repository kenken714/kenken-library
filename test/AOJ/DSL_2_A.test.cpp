#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include <bits/stdc++.h>
#include "../../template/template.cpp"
#include "../../data-str/segment/seg.cpp"

int main(){
    ll n, q;
    cin >> n >> q;
    SegTree seg(n);
    REP(i, q){
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 0) seg.update(b, c);
        if (a == 1) {
            ll res = seg.query(b, c + 1);
            cout << (res == INF ? (1ll << 31) - 1 : res) << endl;
        }
    }
}