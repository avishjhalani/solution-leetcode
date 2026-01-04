class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>nums,vector<int>temp,int i ,int target,int sum){
        if(i>=nums.size() || sum>target){
            return;
        }
        if(sum == target){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums,temp,i,target,sum+nums[i]);
        temp.pop_back();
        solve(nums,temp,i+1,target,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>temp;
        solve(nums,temp,0,target,0);
        return result;
    }
};