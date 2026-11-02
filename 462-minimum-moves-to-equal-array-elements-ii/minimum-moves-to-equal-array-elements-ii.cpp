class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        int mid = nums[(n-1)/2];
        int ans =0;
        for(int i : nums){
            ans+=abs(i-mid);
        }
        return ans;
    }
};