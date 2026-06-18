class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=-1,right=-1;
        int maxseen=nums[0];
        int minseen=nums[n-1];
        //find right most boundary where global ele placing is wrong
        for(int i=1;i<n;i++)
        {
          maxseen=max(maxseen, nums[i]);
          if(nums[i]<maxseen)
          {
            right=i;
          }
        }

        //find left most boundary where global ele placing is wrong
        for(int i=n-2;i>=0;i--)
        {
            minseen= min(minseen, nums[i]);
            if(nums[i]>minseen)
            {
                left=i;
            }
        }
        if(right==-1) return 0;
        return right - left + 1;
    }
};