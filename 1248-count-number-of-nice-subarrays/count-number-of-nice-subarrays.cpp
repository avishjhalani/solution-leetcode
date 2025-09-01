class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0,cnt=0,ans=0,ans2=0,prev_cnt=0;
        while(i<n){
            if(nums[i]%2==1){
                cnt++;
                prev_cnt=0;
            }
            while(cnt==k){
                prev_cnt++;
                if(nums[j]%2!=0){
                    cnt--;
                }
                j++;
            }
            ans+= prev_cnt;
            i++;
        }
        return ans;
    }
};