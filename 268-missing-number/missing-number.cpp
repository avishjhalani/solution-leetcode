class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n =arr.size();
        int sum1 = n*(n+1)/2;
        int sum2 = 0 ;
        for(int i=0;i<n;i++){
            sum2 =sum2+arr[i];
        }
        return sum1 -sum2;
    }
};