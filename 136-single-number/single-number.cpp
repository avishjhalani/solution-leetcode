class Solution {
public:
    int singleNumber(vector<int>& nums) {
    //     if(nums.size()==1) return nums[0];
    //     unordered_map<int,int>mp;
    //     for(auto &it:nums){
    //         mp[it]++;
    //     }
    //     for(auto i :mp){
    //         if(i.second==1) return i.first;
    //     }
    //     return -1;
    // }

    int ans =0;
    for(auto i:nums){
        ans = ans^i;
    }
return ans;
    }
};