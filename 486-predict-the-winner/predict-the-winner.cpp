class Solution {
public:
int t[23][23];
    int solve(int i ,int j,vector<int>&nums){
        if(i>j) return 0;
        if(i==j)return nums[i];
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int takei = nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int takej = nums[j]+min(solve(i,j-2,nums),solve(i+1,j-1,nums));
        return max(takei,takej);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(t,-1,sizeof(t));
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