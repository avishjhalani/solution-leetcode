class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zero = 0;
        for(int i :nums){
            if(i == 0) zero++;
        }
        int n = nums.size();
        int swap =0;
        for(int i =0;i<n-zero ;i++){
            if(nums[i]==0)swap++;
        }
        return swap;
    }
};