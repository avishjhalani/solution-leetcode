class Solution {
public:
// int t[101];
// int solve(vector<int>& nums,int idx){
//     if(idx >= nums.size()){
//         return 0;
//     }
//     if(t[idx]!=-1){
//         return t[idx];
//     }
//         int pick = nums[idx]+solve(nums,idx+2);
//         int notpick = solve(nums,idx+1);
        
//     return t[idx]=std::max(pick,notpick);;
    

// }
//     int rob(vector<int>& nums) {
//         memset(t,-1,sizeof(t));
//         return solve(nums,0);
//     }
// };
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1);
        if(n==0)return 0;
        if(n==1)return nums[0];
        if(n==2)return std::max(nums[0],nums[1]);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i =2;i<n;i++){
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};