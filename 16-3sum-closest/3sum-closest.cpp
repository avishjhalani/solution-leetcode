class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 1000000;
        for(int i =0;i<n-2;i++){
            int j =i+1;
            int k=n-1;
            while(j<k){
                int temp = nums[i]+nums[j]+nums[k];
                if(abs(target -temp) < abs(target - ans )){
                    ans = temp ; 
                }
                if(temp<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans ;
    }
};