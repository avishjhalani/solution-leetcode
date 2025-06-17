class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // vector<int>ans;
        // for(int i =0;i<rowIndex;++i){
        //     long a =1;
        //     vector<int>temp;
        //     for(int j =0;j<=i ;j++){
        //         if(j==0){
        //             temp.push_back(a);
        //         }
        //         else{
        //             a =a*(i-j+1)/j;
        //             temp.push_back(a);
        //         }
        //     }
        //     ans =temp;
        // }
        // return ans;

        long a =1;
        vector<int>ans;
        for(int i =0;i<=rowIndex;i++){
            if(i==0){
                ans.push_back(a);
            }
            else{
                a =a*(rowIndex-i+1)/i;
                ans.push_back(a);
            }
        }
        return ans;
    }
};