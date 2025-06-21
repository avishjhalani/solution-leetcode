class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> s;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            mp[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};

// int n =nums2.size()-1;
// vector<int>ans;
// for(int i =0 ; i<nums1.size();i++){
//     int index ;
//     for(int j =0;j<nums2.size();j++){
//         if(nums1[i] == nums2[j]) index = j;
//     }
//     if(nums2[index] > nums2[index-1] && nums2[index] != nums2[n]){
//         ans.push_back(nums2[index]);

//     }
//     else{
//         ans.push_back(-1);
//     }
// }
// return ans;