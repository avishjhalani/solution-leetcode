class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int x =  nums.size()-k;
        sort(begin(nums),end(nums));
        return nums[x];
    }
};
