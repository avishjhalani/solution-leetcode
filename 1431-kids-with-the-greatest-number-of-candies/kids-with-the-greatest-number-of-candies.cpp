class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& arr, int extra) {
        int n = arr.size();
        int maxcandies = arr[0];
        for(int i =1;i<n;i++){
            if(arr[i]>maxcandies){
                maxcandies= arr[i];
            }
        }
    vector<bool>ans(arr.size(),false);
    for(int i =0;i<arr.size();i++){
        if(arr[i]+extra>=maxcandies){
            ans[i]=true;
        }
    }
    return ans;
    }
};