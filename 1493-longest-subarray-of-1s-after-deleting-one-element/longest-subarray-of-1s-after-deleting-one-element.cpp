class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int j =0;
        int lastzero =-1;
        int result =0;
        while(j<n){
            if(nums[j]==0){
                i = lastzero+1;
                lastzero = j;
            }
            result = max(result , j-i);
            j++;
        }
        return result;
    }
};