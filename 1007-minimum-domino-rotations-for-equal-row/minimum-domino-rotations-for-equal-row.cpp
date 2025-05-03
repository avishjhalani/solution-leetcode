class Solution {
public:
    int findswaps(vector<int>&tops ,vector<int>&bottoms,int val){
        int n =tops.size();
        int swaptop = 0;
        int swapbottom = 0;
        for(int i =0;i<n;i++){
            if(tops[i]!=val && bottoms[i]!=val) return -1;
            else if(tops[i]!=val){
                swaptop++;
            }
            else if(bottoms[i]!=val){
                swapbottom++;
            }
        }
        return min(swaptop,swapbottom);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result =INT_MAX;
        for(int val =0;val<=6;val++){
            int swap = findswaps(tops,bottoms,val);
            if(swap!=-1){
                result = min(result,swap);
            }
        }
        // if(result == INT_MAX){
        //     return -1;
        // }
        // else{
        //     return result;
        // }
        return result==INT_MAX?-1:result;
    }
};