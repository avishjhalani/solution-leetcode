class Solution {
public:
int n;
    int nextJump(int curr , vector<int>&nums){
        return((curr+nums[curr]%n)+n)%n;
    }
    bool circularArrayLoop(vector<int>& nums) {
      n = nums.size();
     for(int i =0;i<n;i++){
        if(nums[i]==0) continue;
        int slow =i;
        int fast =i;
        int dir =nums[i];
        while (true) {

    if (nums[slow] * dir <= 0)
        break;

    if (nums[fast] * dir <= 0)
        break;

    int nextfast = nextJump(fast, nums);

    if (nums[nextfast] * dir <= 0)
        break;

    slow = nextJump(slow, nums);
    fast = nextJump(nextJump(fast, nums), nums);

    if (slow == fast) {
        if (slow == nextJump(slow, nums))
            break;      // one-element loop
        return true;
    }
}
        int curr=i;
        while(nums[curr]*dir>0){
            int next = nextJump(curr,nums);
            nums[curr]=0;
            curr=next;
        }
     }   
     return false;
    }
};