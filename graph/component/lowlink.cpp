struct LowLink{
    vector<vector<int>> g;
    vector<int> ord, low, articulation;
    vector<P> bridge;
    vector<bool> used;
    LowLink(int n) : g(n){};

    void edgeset(int a, int b){
        g[a].push_back(b);
        g[b].push_back(a);
    }

    void dfs(int v, int p, int &t){
        used[v] = true;
        ord[v] = t++;
        low[v] = ord[v];
        bool ar = false;
        int sub = 0;
        for (auto& i : g[v]) {
            if (i == p) continue;
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