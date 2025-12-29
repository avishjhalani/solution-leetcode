class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum =INT_MIN;
        for(int i =0;i<n;i++){
           int sum =nums[i]+sum;
           if(sum>maxsum){
            maxsum = sum;
           }
           if(sum<0){
            sum =0;
           }
        }
        return maxsum;
    }
};