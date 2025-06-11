class Solution {
public:
// int divisor(vector<int>&nums,int threshold){
//      int start =0;
//      int end =INT_MAX;
//      while(start<=end){
//         int mid =start +(end-start)/2;
//         int sum =0;
//         for(int i =0 ;i<nums.length;i++){
//             sum = sum +(nums[i]+nums[mid]-1)/mid;
//         }
//         if(sum<=threshold){
//             end =mid-1;
//         }
//         else{
//             start =mid+1;
//         }
// return start;
//      }
// }
    int smallestDivisor(vector<int>& nums, int threshold) {
       int start =1;
     int end =INT_MAX;
     while(start<=end){
        int mid =start +(end-start)/2;
        int sum =0;
        for(int i =0 ;i<nums.size();i++){
            sum = sum +((nums[i]+mid-1)/mid);
        }
        if(sum<=threshold){
            end =mid-1;
        }
        else{
            start =mid+1;
        }
     }
return start;
     

    }
};