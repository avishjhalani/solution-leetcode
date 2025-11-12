class Solution {
public:
    int strStr(string hay, string nee) {
        if(hay.size()==0){
            return -1;
        }
        // int n = hay.size();
        // int m = nee.size();
        for(int i=0;i<hay.size();i++){
            int j =0;
            while(j<nee.size() && hay[i+j]==nee[j]){
                j++;
            }
            if(j==nee.size()){
                return i;
            }
        }
        return -1;
    }
};