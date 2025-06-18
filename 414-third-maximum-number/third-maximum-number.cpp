class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // set<int>s(nums.begin(),nums.end());
        // vector<int>ans(s.begin(),s.end());
        // if(ans.size()<3){
        //     return ans.back();
        // }
        // return ans[ans.size()-3];
        long fmax =LONG_MIN,smax=LONG_MIN,tmax=LONG_MAX;
        for(auto i :nums){
            if(i==fmax||i==smax||i==tmax) continue;
            if(i>fmax){
                tmax =smax;
                smax=fmax;
                fmax =i;
            }
            else if(i>smax){
                tmax =smax;
                smax =i;
            }
            else if(i>tmax){
                tmax =i;
            }
        }
        if(tmax == LONG_MIN) return fmax;
        return tmax;
    }
};