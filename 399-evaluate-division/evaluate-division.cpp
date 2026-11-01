class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>>& adj,
             string src, string dst, unordered_set<string>& st, double prod,
             double& ans) {
        if (st.find(src) != st.end())
            return;

        st.insert(src);
        if (src == dst) {
            ans = prod;
            return;
        }
        for (auto& p : adj[src]) {
            string u = p.first;
            double val = p.second;

            dfs(adj, u, dst, st, prod * val, ans);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }
        vector<double> result;
        for (auto& querie : queries) {
            string src = querie[0];
            string dst = querie[1];
            double ans = -1.0;
            double prod = 1.0;
            if (adj.find(src) != adj.end()) {
                unordered_set<string> st;
                dfs(adj, src, dst, st, prod, ans);
            }
            result.push_back(ans);
        }
        return result;
    }
};