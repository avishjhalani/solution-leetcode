class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count =0;
        int smaller =0;
        vector<int>ans;
        for(int i =0;i<nums.size();i++){
            if(nums[i]<target){
                smaller++;
            }
            if(nums[i]==target){
                count++;
            }
        }
        if(count == 1){
            return {smaller};
        }
        for(int i=0;i<count;i++){
            ans.push_back(smaller+i);
        }
        return ans;
    }
};