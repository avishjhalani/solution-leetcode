class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int ans =0;
        int mini =arr[0];
        for(int i=0;i<n;i++){
            int profit =arr[i]- mini;
            ans = max(ans ,profit);
            mini = min(mini , arr[i]);
        }
        return ans;
    }
};