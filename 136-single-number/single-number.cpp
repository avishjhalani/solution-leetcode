class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int ans =0;
        for(int i : nums){
            ans =ans^i;
        }
        return ans;
    }
};