class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& pre) {
        vector<vector<int>> adj(N);
        
        
        for (auto &it : pre) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(N, 0);

        
        for (int i = 0; i < N; i++) {
            for (int v : adj[i]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int v : adj[node]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        return count == N;
    }
};
