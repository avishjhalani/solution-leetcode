class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n){
            int corIdx =nums[i]-1;
            if(nums[i]!=nums[corIdx]){
                swap(nums[i],nums[corIdx]);
            }
            else{
                i++;
            }
        }
        for(int i =0;i<n;i++){
            if(i!=nums[i]-1){
                return nums[i];
            }

        }
        return n ;
        
    }
};