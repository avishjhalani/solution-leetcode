class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int n = nums.size();
        int m =nums[0].size();
        int col1 =1;
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==0){
                    nums[i][0]=0;
                    if(j!=0){
                        nums[0][j]=0;
                    }
                    else col1 =0;
                }
            }
        }
        for(int i =1;i<n;i++){
            for(int j=1 ;j<m;j++){
                if(nums[i][j]!=0){
                    if(nums[0][j]==0 || nums[i][0]==0){
                        nums[i][j]=0;
                    }
                }
            }
        }
        if(nums[0][0]==0){
            for(int j =0;j<m;j++){
                nums[0][j]=0;
            }
        }
        if(col1 ==0){
            for(int i =0;i<n;i++){
                nums[i][0]=0;
            }
        }
    }
};