class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ansXOR = 0;

        for (int x : nums) {
            ansXOR ^= x;
        }

        if (ansXOR != 0)
            return n;

        for (int x : nums) {
            if (x != 0)
                return n - 1;
        }

        return 0;
    }
};