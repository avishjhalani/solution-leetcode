class Solution {
public:
    int SumDigit(int i) {
        int sum = 0;
        while (i > 0) {
            sum += i % 10;
            i /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> digitSum;

        for (int x : nums) {
            if (!digitSum.count(x)) {
                digitSum[x] = SumDigit(x);
            }
        }

        vector<int> aftersort(nums);

        auto lambda = [&digitSum](int i, int j) {
            if (digitSum[i] != digitSum[j])
                return digitSum[i] < digitSum[j];
            return i < j;
        };

        sort(aftersort.begin(), aftersort.end(), lambda);

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            int expected = aftersort[i];

            if (curr == expected)
                continue;

            int idx = mp[expected];

            swap(nums[i], nums[idx]);

            mp[nums[idx]] = idx;
            mp[nums[i]] = i;

            count++;
        }

        return count;
    }
};