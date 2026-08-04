class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int>st(nums.begin(),nums.end());
        int start = nums[0];
        int end = nums[nums.size()-1];
        vector<int>ans;
        for(int i =start+1;i<=end-1;i++){
            if(st.count(i)==0)ans.push_back(i);
        }
        return ans;
    }
};