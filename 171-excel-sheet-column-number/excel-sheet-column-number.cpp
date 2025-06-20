class Solution {
public:
    int titleToNumber(string col) {
        int ans =0;
        for(char &ch :col){
            int a = ch -64;
            ans=ans*26+a;
        }
        return ans;
    }
};