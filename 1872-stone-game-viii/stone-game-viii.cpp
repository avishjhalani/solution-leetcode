class Solution {
public:
    int stoneGameVIII(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        vector<int> t(n, 0);
        t[n - 1] = prefixSum[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            int take = prefixSum[i] - t[i + 1];
            int skip = t[i + 1];
            t[i] = max(take, skip);
        }
        return t[1];
    }
};