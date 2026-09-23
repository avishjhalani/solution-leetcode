class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n= nums.size();
        int total =0;
        for(int i :nums){
            total +=i;
        }
        int target =total -x;
        if (target ==0) return n;
        int left =0;
        int sum =0;
        int maxlen =-1;
        for(int right =0;right<n;right++){
            sum+=nums[right];
            while(left<=right && sum>target){
                sum-=nums[left];
                left++;
            }
            if(sum ==target){
                maxlen = max(maxlen,right-left+1);
            }
        }
        return maxlen==-1?-1:n-maxlen;
    }
};