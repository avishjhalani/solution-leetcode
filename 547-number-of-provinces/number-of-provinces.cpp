class Solution {
public:
int n ;
    void dfs(vector<vector<int>>& isConnected,int u ,vector<bool>&visited){
        visited[u] =true;
        for(int i=0;i<n;i++){
            if(!visited[i] && isConnected[u][i]==1){
                dfs(isConnected,i,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n =isConnected.size();
        vector<bool>visited(n,false);
        // unordered_map<int ,vector<int>>adj;
        // for(int i=0;i<n;i++){
        //     for(int j =0;j<n;j++){
        //         if(isConnected[i][j]==1){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        int count =0;
        for(int i =0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};