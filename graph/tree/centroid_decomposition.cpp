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