class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2; 
        int target = nums[mid];
        int count =0;
        for(int i :nums){
            if(i==target) count++;;
        }
        if(count ==1) return true;
        return false;
    }
};