class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& nums) {
        vector<vector<int>>adj(n);
        vector<bool>sus(n,false);
        vector<int>indegree(n,0);
        for(auto & i:nums){
            int u =i[0];
            int v =i[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>que;
        que.push(k);
        sus[k]=true;
        while(!que.empty()){
            int cur =que.front();
            que.pop();
            for(int &ng : adj[cur]){
                indegree[ng]--;
                if(!sus[ng]){
                    que.push(ng);
                    sus[ng] = true;
                }
            }
        }
        vector<int>ans;
        bool check =false;
        for(int i =0;i<n;i++){
            if(sus[i] && indegree[i]>0){
                check =true;
                break;
            }
            if(!sus[i]){
                ans.push_back(i);
            }
        }
        if(check){
            vector<int>arr(n);
            for(int i =0;i<n;i++){
                arr[i]=i;
            }
            return arr;
        }
        return ans;

    }
};