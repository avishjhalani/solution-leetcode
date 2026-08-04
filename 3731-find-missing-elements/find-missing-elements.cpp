class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int minEle = *min_element(nums.begin(),nums.end());
        int maxEle = *max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int idx =0;
        vector<int>ans;
        for(int i =minEle;i<=maxEle;i++){
            while(idx<n && nums[idx]<i){
                idx++;
            }         
            if(idx == n || nums[idx]!=i){
                ans.push_back(i);
            }   
        } 
        return ans;
    }
};