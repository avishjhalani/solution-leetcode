class Solution {
    public int jump(int[] nums) {
        int far=0,near=0,jumps=0;
        while(far<nums.length-1){
            int x=0;
            for(int i=near;i<=far;i++){
                x=Math.max(x,i+nums[i]);
            }
            near=far+1;
            far=x;
            jumps++;
        }
        return jumps;

    }
}