class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n =nums.size();
       vector<int>ans(n,-1);
       stack<int>s;
       for(int i =2*n-1;i>=0;i--){
        int cur =nums[i%n];
        while(!s.empty()&&s.top()<=cur){
            s.pop();
        }
        if(i<n){
            ans[i] = s.empty() ? -1 : s.top();
        }
        s.push(cur);
       }
        return ans;
    }
};



//  unordered_map<int, int> mp;
//         stack<int>s;
        
//          for (int i = 2*nums1.size() - 1; i >= 0; i--) {
//             vector<int>nums2 = nums1[i%n];
//             while (!s.empty() && s.top() <= nums2[i]) {
//                 s.pop();
//             }
//             if(i<n) mp[nums2[i]] = s.empty() ? -1 : s.top();
//             s.push(nums2[i]);
//         }
//         vector<int> ans(n);
//         for (int num : nums1) {
//             ans.push_back(mp[num]);
//         }
//         return ans;