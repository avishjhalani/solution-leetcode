class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int n = nums.size();
        vector<int>uniq;
        unordered_map<int,int>mp;
        for(auto num :nums){
            mp[num]++;
        }
        for(auto &val:mp){
            uniq.push_back(val.first);
        }
        sort(uniq.begin(),uniq.end());
        int x = uniq.size();
        for(int i=0;i<x;i++){
            for(int j=i+1;j<x;j++){
                int x = uniq[i];
                int y = uniq[j];
                if(mp[x]!=mp[y]){
                    return{x,y};
                }
            }
        }
        return{-1,-1};
    }
};