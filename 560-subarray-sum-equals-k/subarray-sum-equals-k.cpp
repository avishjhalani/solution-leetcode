class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
         int n = arr.size();
        unordered_map<int,int>mp;
        int ans =0;
        int sum = 0;
        for(int i =0;i<n;i++){
            sum =sum +arr[i];
            if(sum ==k){
                ans++;
            }
            ans =ans + mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};