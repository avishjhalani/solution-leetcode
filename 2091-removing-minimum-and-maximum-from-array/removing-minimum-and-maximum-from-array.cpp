class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxidx =0;
        int minidx =0;
        int maxele =nums[0];
        int minele =nums[0];
        for(int i =0;i<n;i++){
            if(nums[i]<minele){
                minele =nums[i];
                minidx =i;
            }
            else if(nums[i]>maxele){
                maxele =nums[i];
                maxidx =i;
            }
        }
        if (minidx > maxidx)
            swap(minidx, maxidx);
        int left = maxidx + 1;

        int right = n - minidx;

        int both = (minidx + 1) + (n - maxidx);

        return min({left, right, both});
    }
};