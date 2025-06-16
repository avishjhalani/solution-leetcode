class Solution {
public:
    int countPermutations(vector<int>& arr) {
        int n  =arr.size();
         int MOD = 1e9 + 7;
        if(arr[0]!=*min_element(arr.begin(),arr.end()) ||
            count(arr.begin(),arr.end(),arr[0])>1){
            return 0;
                   }
           
        long long ans = 1;
        for (int i = 1; i < n; ++i) {
            ans = (ans * i) % MOD;
        }
        return (int)ans;
    }
};