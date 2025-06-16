// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n =height.size();
//        vector<int> left(n,0) ,right(n,0);
//        for(int i =1;i<n;i++){
//         left[i] = max(left[i-1],height[i-1]);
//        }
//        for(int i=n-2;i>0;i--){
//         right[i] = max(right[i+1],height[i+1]);
//        }
//        int water =0;
//        for(int i =1; i<n-1;i++){
//         if(left[i]>height[i]&&right[i]>height[i]){
//             water += min(left[i],right[i])-height[i];
//         }
//        }
//        return water;
//     }
// };                          
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int leftmax=0;
        int rightmax=0;
        int total=0;
        while(left<right) {
            if(height[left]<=height[right]) {
                if(leftmax>height[left]) {
                    total=total+(leftmax-height[left]);
                } else {
                    leftmax=height[left];
                }

                left=left+1;
            } else {
                if(rightmax>height[right]) {
                    total=total+(rightmax-height[right]);
                } else {
                    rightmax=height[right];
                }

                right=right-1;
            }
        }

        return total;
        
    }
};