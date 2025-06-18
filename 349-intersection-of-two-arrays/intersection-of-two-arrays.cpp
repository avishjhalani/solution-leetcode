class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n =nums1.size();
        int m = nums2.size();
        unordered_set<int>s;
        for(auto i:nums1){
            s.insert(i);
        }
        vector<int>ans;
        for(int i :nums2){
            if(s.find(i)!=s.end()){
                ans.push_back(i);
                s.erase(i);
            }
        }
        return ans;
        
    }
};