class Solution {
public:
vector<vector<int>>st;
    void solve(vector<int>&temp,int i,vector<int>&nums){
        if(i==nums.size()){
            st.push_back(temp);
            return;
        }
        if(i>nums.size())return;
        temp.push_back(nums[i]);
        solve(temp,i+1,nums);
        temp.pop_back();
        solve(temp,i+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        solve(temp,0,nums);
        // vector<vector<int>>result(st.begin(),st.end());
        return st;
    }
};