class Solution {
public:
    int MOD = 1e9 + 7;
    int memo[201][201][201];
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int solve(vector<int>& nums, int i, int j, int k) {
        if (i == nums.size()) {
            bool bothNon = (j != 0 && k != 0);
            bool GCDmatch = (j == k);
            return (bothNon && GCDmatch) ? 1 : 0;
        }
        if(memo[i][j][k]!=-1){
            return memo[i][j][k];
        }
        int skip = solve(nums, i + 1, j, k);
        int take1 = solve(nums,i+1, gcd(j, nums[i]), k);
        int take2 = solve(nums,i+1, j, gcd(k, nums[i]));

        return memo[i][j][k]=(0LL+skip + take1 + take2) % MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        return solve(nums, 0, 0, 0); 
    }
};