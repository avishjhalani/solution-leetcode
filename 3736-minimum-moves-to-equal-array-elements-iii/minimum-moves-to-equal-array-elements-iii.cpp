class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        int maxele = *max_element(begin(nums),end(nums));
        for(int i: nums){
            ans+=maxele-i;
        }
        return ans;
    }
};