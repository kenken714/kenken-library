#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include <bits/stdc++.h>
#include "../../other/macro.cpp"
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