class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int val = *left.rbegin();
                left.erase(left.find(val));
                sumL -= val;

                right.insert(val);
                sumR += val;
            }

            while (left.size() < right.size()) {
                int val = *right.begin();
                right.erase(right.find(val));
                sumR -= val;

                left.insert(val);
                sumL += val;
            }
        };

        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumL += val;
            } else {
                right.insert(val);
                sumR += val;
            }

            balance();
        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumL -= val;
            } else {
                it = right.find(val);
                right.erase(it);
                sumR -= val;
            }

            balance();
        };

        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();

            return median * left.size() - sumL + sumR - median * right.size();
        };

        int m = n - x + 1;
        vector<long long> cost(m);

        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int cnt = 1; cnt <= k; cnt++) {

                dp[i][cnt] = dp[i + 1][cnt];
                if (dp[i + x][cnt - 1] != INF) {
                    dp[i][cnt] = min(dp[i][cnt], cost[i] + dp[i + x][cnt - 1]);
                }
            }
        }

        return dp[0][k];
    }
};