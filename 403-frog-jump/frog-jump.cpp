class Solution {
public:
    int n ;
    unordered_map<int,int> mp;
    int t[2001][2001];
int solve(vector<int>&stones ,int cur_stone_idx,int prevjumps){
    if(cur_stone_idx == n-1){
        return true;
    }
    if(t[cur_stone_idx][prevjumps]!=-1) return t[cur_stone_idx][prevjumps];
    bool result =false;
    for(int nextjump = prevjumps-1;nextjump<=prevjumps+1;nextjump++){
        if(nextjump>0){
            int nextstone =stones[cur_stone_idx]+nextjump;
            if(mp.find(nextstone)!=mp.end()){
                result = result || solve(stones ,mp[nextstone] ,nextjump );
            }
        }
    }
    return t[cur_stone_idx][prevjumps]=result;
}

    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1]!=1) return false;
        for(int i =0;i<n;i++){
            mp[stones[i]]=i;
        }
        memset(t,-1,sizeof(t));
        return solve(stones,0,0);    
    }
};