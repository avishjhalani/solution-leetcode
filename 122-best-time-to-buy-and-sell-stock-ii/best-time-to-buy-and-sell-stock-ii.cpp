class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i =0 ;i<n-1;i++){
            if(arr[i+1]>arr[i]){
                int profit =arr[i+1] -arr[i];
                ans = ans + profit;
            }
        }
        return ans;
    }
};