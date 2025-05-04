class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        map<pair<int,int>,int>mp; 
        for(auto &x:d){
            if(x[0]>x[1]) swap(x[0],x[1]);
            mp[{x[0],x[1]}]++;

        }
        int result = 0 ;
        for(auto &it:mp){
            int freq = it.second;
            result += freq * (freq-1)/2;
        }
        return result;
    }
};