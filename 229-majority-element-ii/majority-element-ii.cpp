class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i : nums){
            mp[i]++;
        }
        vector<int>ans;
        for(auto it:mp){
            int x = it.second;
            if(x>n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};