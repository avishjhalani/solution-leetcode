class Solution {
public:
int MOD = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>count(32,0);
        for(int i:nums){
            for(int b =0;b<32;b++){
                if(i&(1<<b)){
                    count[b]++;
                }
            }
        }
        long long result =0;
        while(k--){
            long long curr =0;
            for(int i =0;i<32;i++){
                if(count[i]>0){
                    curr  = (curr | (1<<i));
                    count[i]--;
                }
            }
            result = (result+(curr*curr))%MOD;
        }
        return (int)result;
    }
};