#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include <bits/stdc++.h>
#include "../../template/template.cpp"
#include "../../data-str/segment/bit.cpp"

int main(){
    ll n, q;
    cin >> n >> q;
    REP(i, q){
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 0) add(b, c);
        if (a == 1) cout << sum(c) - sum(b - 1) << endl;
    }
}