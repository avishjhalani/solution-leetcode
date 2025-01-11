class Solution {
    public boolean canJump(int[] nums) {
         int goal=nums.length-1;
        int n =nums.length-2;
        for(int i =n;i>=0;i--){
            if(i+nums[i]>=goal){
                goal=i;
            }
        }
    
    return goal==0;
    }
}