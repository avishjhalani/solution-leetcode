class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left =0;
        int maxsum =0;
        int len = INT_MAX;
        for(int right =0;right<n;right++){
            maxsum +=nums[right];
            while(maxsum>=target){
                if(right-left+1<len){
                    len = right-left+1;
                }
                maxsum -=nums[left];
                left++;
            }
        }
        if(len>n) return 0;
        else return len;
    }
};