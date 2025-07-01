class Solution {
public:
    int numSquares(int n) {
        vector<long>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i =1;i<=n;i++){
            for(int j=0;j*j<=i;j++){
                if(dp[i-j*j]+1!=INT_MAX){
                dp[i] =min(dp[i],dp[i-j*j]+1);
            }
            }
        }
        return dp[n];
    }
};