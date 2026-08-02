class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx =0;
        for(int i =m+n-1;i>m-1;i--){
            nums1[i]=nums2[idx];
            idx++;
        }
        sort(nums1.begin(),nums1.end());
        
    }
};