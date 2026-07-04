class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int best = INT_MIN;
        int maxLEFT= INT_MIN;
        for(int i =0;i<n;i++){
            int j =i-k;
            if(j>=0){
                maxLEFT = max(maxLEFT , nums[j]);
            }
            if(maxLEFT != INT_MIN){
                best = max(best ,maxLEFT+nums[i]);
            }
        }
        return best;
    }
};