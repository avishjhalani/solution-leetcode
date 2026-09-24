class Solution {
public:
int sum(int i){
    int sum =0;
    while(i>0){
        int temp = i%10;
        sum +=temp;
        i =i/10;
    }
    return sum;
}
    int smallestIndex(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            if(sum(nums[i])==i) return i;
        }
        return -1;
    }
};