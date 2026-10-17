class Solution {
public:
    int SumDigit(int i){
        int sum =0;
        while(i>0){
            sum+=(i%10);
            i=i/10;
        }
        return sum;
    } 
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>aftersort(nums);
        auto lambda=[this](int i,int j ){
            int sumd1 = SumDigit(i);
            int sumd2 = SumDigit(j);
            if(sumd1!=sumd2) return sumd1<sumd2;
            return i<j;
        };
        sort(begin(aftersort),end(aftersort),lambda);
        unordered_map<int,int>mp;
        for(int i =0;i<n;i++){
            mp[nums[i]]=i;
        }
        int count =0;
        for(int i =0;i<n;i++){
            int curr = nums[i];
            int expected = aftersort[i];
            if(curr == expected){
                continue;
            }
            int idx = mp[expected];
            swap(nums[i],nums[idx]);
            mp[nums[idx]] = idx;
            mp[nums[i]] = i;
            count++;
        }
        return count;
    }
};