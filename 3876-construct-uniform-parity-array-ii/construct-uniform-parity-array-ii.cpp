class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int smallestOdd = INT_MAX;
        int even =0;
        for (int x : nums) {
            if (x % 2 == 1)
                smallestOdd = min(smallestOdd, x);
            else even++;
        }
        if(even == n) return true;
        for (int x : nums) {
            if (x % 2 == 0 && x < smallestOdd)
                return false;
        }

        return true;
    }
};