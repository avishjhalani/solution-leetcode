class Solution {
public:
    int solve(int i ,int j,vector<int>&nums){
        if(i>j) return 0;
        if(i==j)return nums[i];
        int takei = nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int takej = nums[j]+min(solve(i,j-2,nums),solve(i+1,j-1,nums));
        return max(takei,takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        int total =0;
        for(int i:nums){
            total +=i;
        }
        int first = solve(0,nums.size()-1,nums);
        if(first>=total-first){
            return true;
        }
        return false;
    }
};