class Solution {
public:
    int MOD = 1e9+7;
    
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int ans =0;
        int count1 =0,count2 =0;
        for(int i :nums){
            int j;
            if(i<a)j=0;
            else if(i<=b)j=1;
            else j=2;

            if(j==0){
                ans= (ans+count1+count2)%MOD;
            }
            else if(j==1) {
                ans =(ans+count2)%MOD;
                count1++;
            }
            else{
                count2++;
            }
        }
        return ans;
    }
};