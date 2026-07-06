class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        int n = nums.size();
        int count = 1;
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1]; // larger end first
            return a[0] < b[0];
        });
        int end = nums[0][1];
        for (int i = 1; i < n; i++) {
            if (end < nums[i][1]) {
                count++;
                end = nums[i][1];
            }
        }
        return count;
    }
};