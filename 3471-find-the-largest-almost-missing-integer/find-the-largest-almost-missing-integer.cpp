class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        // Frequency of each element
        for (int x : nums) {
            mp[x]++;
        }

        // k == 1
        // Each subarray contains one element, so we need
        // the largest element that occurs exactly once.
        if (k == 1) {
            int ans = -1;

            for (auto [x, freq] : mp) {
                if (freq == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // k == n
        // There is only one subarray, so every element
        // present in nums belongs to exactly one subarray.
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // 1 < k < n
        // Only the first and last elements can belong to
        // exactly one subarray.
        int first = nums[0];
        int last = nums[n - 1];

        if (mp[first] == 1 && mp[last] == 1) {
            return max(first, last);
        }

        if (mp[first] == 1) {
            return first;
        }

        if (mp[last] == 1) {
            return last;
        }

        return -1;
    }
};