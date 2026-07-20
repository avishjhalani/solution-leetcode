class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        int temp=0;
        for(int i =0;i<n;i++){
            if(nums[i]==1){
                temp++;
            }
            if(nums[i]==0){
                ans =max(temp,ans);
                temp =0;
            }
        }
        return max(temp,ans);
    }
};