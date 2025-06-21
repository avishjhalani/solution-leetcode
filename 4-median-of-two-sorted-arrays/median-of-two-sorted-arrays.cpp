class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>ans;
        // double value=0;
        // for(int i =0;i<nums1.size();i++){
        //     ans.push_back(nums1[i]);
        // }
        // for(int i =0;i<nums2.size();i++){
        //     ans.push_back(nums2[i]);
        // }
        // sort(ans.begin(),ans.end());
        // double n =ans.size()/2;
        // if(ans.size()%2==1){
        //     value = ans[n];
        // }
        // else{
        //     value = (ans[n]+ans[n- 1])/2.0;
        // }
        // return value;

        
        vector<int> ans = nums1;
        ans.insert(ans.end(), nums2.begin(), nums2.end());
        sort(ans.begin(), ans.end());

        int n = ans.size();
        if (n % 2 == 1) {
            return ans[n / 2];
        } else {
            return (ans[n / 2 - 1] + ans[n / 2]) / 2.0;
        }
    }
};