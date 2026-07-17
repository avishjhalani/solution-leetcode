class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> divCnt(mx + 1, 0);

        // Count numbers divisible by d
        for (int d = 1; d <= mx; d++) {
            for (int j = d; j <= mx; j += d)
                divCnt[d] += freq[j];
        }

        vector<long long> gcdCnt(mx + 1, 0);

        // Inclusion-exclusion
        for (int d = mx; d >= 1; d--) {
            gcdCnt[d] = divCnt[d] * (divCnt[d] - 1) / 2;
            for (int j = 2 * d; j <= mx; j += d)
                gcdCnt[d] -= gcdCnt[j];
        }

        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + gcdCnt[i];

        vector<int> ans;
        for (long long q : queries) {
            // q is 0-indexed
            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};