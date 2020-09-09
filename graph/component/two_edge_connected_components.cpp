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